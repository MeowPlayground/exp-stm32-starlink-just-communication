#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "main.h"

// 接收的状态变量
extern uint8_t led1_status;
extern uint8_t led2_status;
extern uint8_t fan_status;
extern uint8_t motor_status;

// 初始化函数
void Receiver_UART_Init(UART_HandleTypeDef *huart);

// 接收中断回调（需在主程序中手动调用）
void Receiver_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif
