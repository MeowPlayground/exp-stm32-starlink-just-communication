#ifndef __LD2402_H__
#define __LD2402_H__

#include "stm32f1xx_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define RX_BUFFER_TIMEOUT 1000 // 接收超时（ms）

    // ========== 公共变量 ==========
    extern uint8_t distance; // 存储解析出的距离值（0~255）

    // ========== 函数声明 ==========

    /**
     * @brief 初始化LD2402传感器所用的UART
     * @param huart UART句柄（如 &huart2）
     */
    void LD2402_Init(UART_HandleTypeDef *huart);

    /**
     * @brief 串口接收完成中断回调函数
     *        需要在 HAL_UART_RxCpltCallback 中调用
     * @param huart 触发中断的 UART 句柄
     */
    void LD2402_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif // __LD2402_H__
