#ifndef __RECEIVER_H
#define __RECEIVER_H

#include "stm32f1xx_hal.h" // 根据你的芯片型号修改

#ifdef __cplusplus
extern "C"
{
#endif

    // 公共变量（供外部访问）
    extern uint16_t received_distance;
    extern float received_temperature;
    extern float received_humidity;
    extern uint16_t received_lux;
    extern uint8_t received_gas; // 新增：接收的 gas 数据
    // 初始化函数（在主函数中调用一次即可）
    void Receiver_UART_Init(UART_HandleTypeDef *huart);

    // 中断回调（在 HAL_UART_RxCpltCallback 中调用）
    void Receiver_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif // __RECEIVER_H
