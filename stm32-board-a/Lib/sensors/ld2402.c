#include "ld2402.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "usart.h"

// ======== 配置区域 ========
#define RX_BUFFER_SIZE 64

// ======== 全局变量 ========
UART_HandleTypeDef *ld2402_uart = NULL;
uint8_t distance = 0; // 解析出的距离值

// ======== 内部静态变量 ========
static uint8_t rx_temp = 0;               // 串口接收临时字节
static uint8_t rx_buffer[RX_BUFFER_SIZE]; // 接收缓存
static uint8_t rx_index = 0;              // 接收索引
static uint8_t last_char = 0;             // 上一个接收到的字节
static uint32_t last_receive_tick = 0;

/**
 * @brief 初始化LD2402传感器（通过UART）
 *
 * @param huart 使用的UART句柄（如&huart2）
 */
void LD2402_Init(UART_HandleTypeDef *huart)
{
    ld2402_uart = huart;                           // 直接存储原始句柄指针
    HAL_UART_Receive_IT(ld2402_uart, &rx_temp, 1); // 启动中断接收
}

/**
 * @brief 串口接收中断回调，用于解析"distance:xxx\r\n"
 *
 * @param huart 当前触发中断的UART
 */

void LD2402_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (ld2402_uart == NULL || huart->Instance != ld2402_uart->Instance)
        return;

    uint32_t now = HAL_GetTick();

    // 超时判断：如果上一次数据已经过去太久，清空接收缓存
    if (now - last_receive_tick > RX_BUFFER_TIMEOUT)
    {
        rx_index = 0;
        memset(rx_buffer, 0, RX_BUFFER_SIZE);
    }

    last_receive_tick = now; // 记录最后接收时间

    if ((last_char == '\r' && rx_temp == '\n') || rx_index >= RX_BUFFER_SIZE - 1)
    {
        if (rx_index >= 2 && rx_index < RX_BUFFER_SIZE)
        {
            rx_buffer[rx_index - 1] = '\0'; // 替换 '\r' 为 '\0'

            if (strncmp((char *)rx_buffer, "distance:", 9) == 0)
            {
                int value = atoi((char *)(rx_buffer + 9));
                if (value >= 0 && value <= 9999)
                {
                    distance = (uint16_t)value;
                }
            }
        }

        rx_index = 0;
        memset(rx_buffer, 0, RX_BUFFER_SIZE);
    }
    else
    {
        if (rx_index < RX_BUFFER_SIZE - 1)
        {
            rx_buffer[rx_index++] = rx_temp;
        }
    }

    last_char = rx_temp;
    HAL_UART_Receive_IT(ld2402_uart, &rx_temp, 1);
}