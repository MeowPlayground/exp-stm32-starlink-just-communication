#include "board.h"
#include "aht20.h"
#include "bh1750.h"
#include "i2c.h"
#include "adc.h"
#include "usart.h"
#include "tim.h"
// 初始化传感器
void sensor_init(void)
{
    AHT20_Init(&hi2c1);  // 初始化 AHT20 传感器
    BH1750_Init(&hi2c1); // 初始化 BH1750 传感器
}

// 获取mp4传感器的浓度信息，AD读取
uint8_t get_mp4_concentration(void)
{
    HAL_ADC_Start(&hadc1);                            // 启动ADC转换
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY); // 等待转换完成
    // ADC 1 IN 0
    uint32_t adc_value = HAL_ADC_GetValue(&hadc1); // 获取ADC值
    // 将ADC值转换为浓度值
    uint8_t concentration = (uint8_t)((adc_value * 100) / 4095); // 将ADC值转换为0-100的浓度值

    HAL_ADC_Stop(&hadc1); // 停止ADC转换

    // 线性处理
    concentration = (concentration > 14) ? (concentration - 14) : 0;

    return concentration; // 返回浓度值
}

// 设置led1和led2的状态 PB3 和 PB4. 低电平点亮
void set_led1(uint8_t state)
{
    if (!state)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET); // 点亮LED1
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // 熄灭LED1
    }
}

void set_led2(uint8_t state)
{
    if (!state)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET); // 点亮LED2
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET); // 熄灭LED2
    }
}

// 设置两个电机TIM3CH3和CH4
void set_motor1_speed(uint16_t speed)
{
    if (speed > 99)
        speed = 99;                                      // 限制最大速度
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, speed); // 设置TIM3通道3的比较值
}

void set_motor2_speed(uint16_t speed)
{
    if (speed > 99)
        speed = 99;                                      // 限制最大速度
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, speed); // 设置TIM3通道4的比较值
}

void motor_init(void)
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); // 启动TIM3通道3的PWM
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); // 启动TIM3通道4的PWM
    // PA1 STBY
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // 设置PA1为高电平，启用电机驱动
}

void motor1_start(void)
{
    // PA4 1, PA5 0
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // 设置PA4为高电平
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // 设置PA5为低电平
}

void motor1_stop(void)
{
    // PA4 0, PA5 0
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // 设置PA4为低电平
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // 设置PA5为低电平
}

void motor2_start(void)
{
    // PA6 1, PA7 0
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);   // 设置PA6为高电平
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // 设置PA7为低电平
}

void motor2_reverse(void)
{
    // PA6 0, PA7 1
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); // 设置PA6为低电平
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);   // 设置PA7为高电平
}

void motor2_stop(void)
{
    // PA6 0, PA7 0
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); // 设置PA6为低电平
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // 设置PA7为低电平
}