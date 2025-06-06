#include <stdio.h>
#include <string.h>

#include "user.h"
#include "board.h"
#include "ld2402.h"
#include "usart.h"
#include "aht20.h"
#include "bh1750.h"
#include "i2c.h"
#include "tim.h"

#include "reciver.h"

uint8_t u1_rx_byte = 0; // 串口1接收字节

void send_sensor_data_uart3(void)
{
    uint8_t buffer[18]; // 原来是17，现在是18字节

    float temperature = 0.0f, humidity = 0.0f;
    uint16_t lux = 0;
    uint8_t gas = get_mp4_concentration(); // 获取气体浓度
    AHT20_ReadData(&hi2c1, &temperature, &humidity);
    BH1750_ReadData(&hi2c1, &lux);

    buffer[0] = 0xAA;
    buffer[1] = 0x55;

    // Distance（uint16_t 小端）
    buffer[2] = distance & 0xFF;
    buffer[3] = (distance >> 8) & 0xFF;

    // Temperature（float 小端）
    memcpy(&buffer[4], &temperature, sizeof(float));

    // Humidity（float 小端）
    memcpy(&buffer[8], &humidity, sizeof(float));

    // Lux（uint16_t 小端）
    buffer[12] = lux & 0xFF;
    buffer[13] = (lux >> 8) & 0xFF;

    // Gas（uint8_t）
    buffer[14] = gas;

    // 校验和：从第2位开始加到第14位（包含gas）
    uint8_t checksum = 0;
    for (int i = 2; i <= 14; ++i)
    {
        checksum += buffer[i];
    }
    buffer[15] = checksum;

    // 结尾
    buffer[16] = '\r';
    buffer[17] = '\n';

    HAL_UART_Transmit(&huart3, buffer, sizeof(buffer), 100);
    printf("Sent data: Distance=%d, Temperature=%.2f, Humidity=%.2f, Lux=%d, Gas=%d\n",
           distance, temperature, humidity, lux, gas);
}



void setup(void)
{
    // This function is called once at the start
    // Add your initialization code here
    printf("System Init\n");
    LD2402_Init(&huart2);                         // 初始化 LD2402 传感器
    sensor_init();                                // 初始化其他传感器
    motor_init();                                 // 初始化电机
    HAL_UART_Receive_IT(&huart1, &u1_rx_byte, 1); // 启动串口1接收中断
    HAL_Delay(200);                               // 等待传感器稳定
	  Receiver_UART_Init(&huart3);                  // 初始化接收器
    HAL_TIM_Base_Start_IT(&htim4);                // 启动定时器4中断
}

uint8_t last_motor_status = 0; // 上一次电机状态


void loop(void)
{
    HAL_Delay(500);
		send_sensor_data_uart3();
    set_led1(led1_status); // 设置LED1状态
    set_led2(led2_status); // 设置LED2状态

    if (fan_status)
    {
        set_motor1_speed(50); // 设置电机速度为50
        motor1_start();       // 启动电机
    }
    else
    {
        set_motor1_speed(0); // 停止电机
        motor1_stop();       // 停止电机
    }

    // 如果motor状态发生变化，则正转一会
    if (motor_status != last_motor_status)
    {
        if (motor_status)
        {
            set_motor2_speed(15); // 设置电机速度为50
            motor2_start();       // 启动电机
        }
        else
        {
            set_motor1_speed(15); // 停止电机
            motor2_reverse();     // 反转电机
        }
        HAL_Delay(2000);                  // 等待1秒钟
        last_motor_status = motor_status; // 更新上一次状态
    }
    else
    {
        motor2_stop(); // 如果状态没有变化，则停止电机
    }
}

// tim中断
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM4)
    {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        //send_sensor_data_uart3(); // 发送传感器数据到 UART3
    }
}


// 串口接收中断回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	  Receiver_UART_RxCpltCallback(huart); // 调用接收器的回调函数
    LD2402_UART_RxCpltCallback(huart);   // 调用 LD2402 的回调函数
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