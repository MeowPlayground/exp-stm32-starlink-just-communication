// page_alarm.c
#include "board.h"

void start_alert()
{
    // 打开tim4
    HAL_TIM_Base_Start_IT(&htim4); // 启动定时器4中断
}

void stop_alert()
{
    // 关闭tim4
    HAL_TIM_Base_Stop_IT(&htim4); // 停止定时器4中断
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
}