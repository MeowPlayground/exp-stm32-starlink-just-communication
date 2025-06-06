#include <stdio.h>

#include "user.h"
#include "meow_oled.h"
#include "receiver.h"

#include "board.h"
#include "page.h"
#include "ds1307.h"

// 1.板子A接传感器与电机、风扇、LED，但不处理信息，信息通过星闪传到板子B来处理再返回板子A
// 2. OLED显示屏实时显示温湿度、天然气浓度、光照值、当前时间等
// 3.1当天然气超过阈值，蜂鸣器响、LED3闪烁、风扇开启，OLED显示警报天然气泄露，通过按键关闭；
// 3.2 当温湿度高或低于阈值一段时间(2S?)，打开LED2；
// 4.可以手动设定时间，在时间段白天，光照高于阈值一段时间，电机正转一小会儿；从高变低又低于阈值一段时间后，电机反转一小会儿；（电机慢速转）
// 5.在时间段晚上，光照低于阈值一段时间，打开LED1；
// 6.雷达模块可手动选择开关，开启后，感应到物体靠近就报警，蜂鸣器响、LED3闪 ，OLED显示警报有人靠近，通过按键关闭
// 7.传感器报警阈值范围可通过按键调整；按键可以手动控制电机、风扇、LED1和2开关
// 8.按键能做到：确认、取消、上、下、切换实时界面或者调整阈值界面

void setup(void)
{
    Receiver_UART_Init(&huart3); // 初始化接收器
    Meow_OLED_Init(&hi2c1);
    HAL_Delay(100);               // 等待OLED初始化完成
    DS1307_Init(&hi2c1);          // 初始化DS1307 RTC
    HAL_Delay(100);               // 等待DS1307初始化完成
    Load_Thresholds_From_Flash(); // 从EEPROM加载阈值
    HAL_Delay(100);               // 等待加载完成
    // 启动TIM2，1s中断，更新时间
    HAL_TIM_Base_Start_IT(&htim2);
    Meow_OLED_ClearScreen();
    init_pages(); // 初始化第一页

    // 开启自动控制定时器
    HAL_TIM_Base_Start_IT(&htim3); // 启动TIM3，自动控制定时器
}

void alert_handle()
{
    // 天然气浓度超过阈值，蜂鸣器响、LED3闪烁、风扇开启
    if (alert_cooldown > HAL_GetTick())
    {
        return; // 如果在冷却时间内，不处理报警
    }

    if (received_gas > 25)
    {
        fan_status = 1;             // 打开风扇
        alert_type = 1;             // 设置报警类型为天然气泄漏
        switch_to_page(PAGE_ALARM); // 切换到报警页面
        start_alert();              // 启动报警
    }
    if (received_distance < 100 && radio_status == 1)
    {
        alert_type = 2;             // 设置报警类型为有人靠近
        switch_to_page(PAGE_ALARM); // 切换到报警页面
        start_alert();              // 启动报警
    }
}

void send_ctrl_data()
{
    // 发送控制数据到板子B
    uint8_t data[9];
    // 假设数据格式为：0xAA, 0x55, LED1状态, LED2状态, 风扇状态，电机状态, 校验位, 0x0D, 0x0A
    data[0] = 0xAA;
    data[1] = 0x55;
    data[2] = led1_status;  // LED1状态
    data[3] = led2_status;  // LED2状态
    data[4] = fan_status;   // 风扇状态
    data[5] = motor_status; // 电机状态
    uint8_t checksum = 0;
    for (int i = 2; i < 6; i++)
    {
        checksum += data[i];
    }
    data[6] = checksum;                                 // 校验位
    data[7] = '\r';                                     // 帧尾
    data[8] = '\n';                                     // 帧尾
    HAL_UART_Transmit(&huart3, data, 9, HAL_MAX_DELAY); // 发送数据到板子B
    printf("Sent control data: LED1=%d, LED2=%d, Fan=%d, Motor=%d\n",
           led1_status, led2_status, fan_status, motor_status);
}

#define CONTINUOUS_TIME_THRESHOLD 2000 // 连续超限/低值触发控制的时间阈值（单位：毫秒）

// 用于记录连续超限/低值时的起始时间
uint32_t temp_continuous_time = 0; // 温湿度连续异常起始时间
uint32_t lux_high_time = 0;        // 光照强度高于阈值的起始时间
uint32_t lux_low_time = 0;         // 光照强度低于阈值的起始时间

/**
 * @brief 自动控制处理函数
 *        根据温湿度、光照以及时间，实现自动控制LED与电机（窗帘）
 */
void auto_ctrl_handle()
{
    // 获取当前系统运行时间（单位：ms）
    uint32_t now = HAL_GetTick();

    /***************************************************************
     * 1️⃣ 温湿度超限报警处理逻辑：
     *    - 若温度或湿度超出设定范围，计时持续超出2秒后点亮LED2
     *    - 否则熄灭LED2
     ***************************************************************/
    if (received_temperature > temp_high_threshold || received_temperature < temp_low_threshold ||
        received_humidity > humidity_high_threshold || received_humidity < humidity_low_threshold)
    {
        if (temp_continuous_time == 0)
            temp_continuous_time = now; // 第一次检测到超限，记录当前时间
        else if (now - temp_continuous_time >= CONTINUOUS_TIME_THRESHOLD)
            led2_status = 1; // 持续超限达到阈值，点亮LED2
    }
    else
    {
        temp_continuous_time = 0; // 清除计时
        led2_status = 0;          // 恢复正常范围，熄灭LED2
    }

    /***************************************************************
     * 2️⃣ 白天窗帘自动控制逻辑（6点~18点）：
     *    - 光照持续高 → 打开窗帘（motor_status = 1）
     *    - 光照持续低 → 关闭窗帘（motor_status = 0）
     *    - 所有动作都需要持续满足条件超过2秒才执行
     ***************************************************************/
    if (current_time.hours >= 6 && current_time.hours < 18)
    {
        // 光照高于阈值，准备打开窗帘
        if (received_lux > light_threshold)
        {
            if (lux_high_time == 0)
                lux_high_time = now; // 第一次检测到高光照，开始计时
            else if (now - lux_high_time >= CONTINUOUS_TIME_THRESHOLD)
            {
                motor_status = 1; // 持续光照高，发送窗帘打开指令
                lux_low_time = 0; // 清除“低光照”方向的计时
            }
        }
        else
        {
            lux_high_time = 0; // 光照未持续高，清除高光照计时
        }

        // 光照低于阈值，准备关闭窗帘
        if (received_lux < light_threshold)
        {
            if (lux_low_time == 0)
                lux_low_time = now; // 第一次检测到低光照，开始计时
            else if (now - lux_low_time >= CONTINUOUS_TIME_THRESHOLD)
            {
                motor_status = 0;  // 持续光照低，发送窗帘关闭指令
                lux_high_time = 0; // 清除“高光照”方向的计时
            }
        }
        else
        {
            lux_low_time = 0; // 光照未持续低，清除低光照计时
        }
    }
    else
    {
        /***************************************************************
         * 3️⃣ 晚上光照提示（18点~次日6点）：
         *    - 光照低于阈值 → 点亮LED1 作为提醒
         *    - 光照高于阈值 → 熄灭LED1
         *    - 晚上不再控制窗帘开关
         ***************************************************************/
        if (received_lux < light_threshold)
            led1_status = 1; // 光照低，点亮提示灯
        else
            led1_status = 0; // 光照正常，关闭提示灯

        // 清除白天控制相关的计时器，防止干扰
        lux_high_time = 0;
        lux_low_time = 0;
    }
}

void loop(void)
{
    // 停止tim2
    HAL_TIM_Base_Stop_IT(&htim2);
    run_current_page_loop();
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_Delay(100); // 延时100毫秒
    alert_handle(); // 处理报警逻辑
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    Receiver_UART_RxCpltCallback(huart);
}

// EXIT中断
// 消抖，20ms
static uint32_t last_interrupt_time = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint32_t current_time = HAL_GetTick();
    // 检查是否在20ms内触发了中断
    if (current_time - last_interrupt_time < 100)
    {
        return; // 如果在20ms内再次触发，则忽略此次中断
    }
    last_interrupt_time = current_time; // 更新上次中断时间

    if (GPIO_Pin == GPIO_PIN_5)
    {
        // 切换到下一个页面
        int next_page = (current_page + 1) % PAGE_COUNT;
        switch_to_page(next_page);
        current_page = next_page; // 更新当前页面索引
        if (current_page == PAGE_HOME)
        {
            // 打开tim2
            HAL_TIM_Base_Start_IT(&htim2); // 启动TIM2，更新时间
        }
        else
        {
            // 停止tim2
            HAL_TIM_Base_Stop_IT(&htim2); // 停止TIM2，避免更新时间
        }
    }
    else if (
        pages[current_page].button_event_handler != NULL) // 如果当前页面有按钮事件处理函数
    {
        // 调用当前页面的按钮事件处理函数
        pages[current_page].button_event_handler(GPIO_Pin);
    }
}

// tim2中断
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
    }
    else if (htim->Instance == TIM3)
    {
        if (auto_mode)
            auto_ctrl_handle(); // 自动控制处理函数
        send_ctrl_data();

        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // 翻转PC13引脚状态
    }
    else if (htim->Instance == TIM4)
    {
        // 翻转beep和LED，PA2，PB3
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); // 翻转PA2引脚状态
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3); // 翻转PB3引脚状态
    }
}

// 重定向printf函数
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
    return ch;
}

int fgetc(FILE *f)
{
    uint8_t ch = 0;
    HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
    return ch;
}