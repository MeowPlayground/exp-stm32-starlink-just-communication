#include "receiver.h"
#include <string.h>
#include <stdio.h>

#define UART_RX_FRAME_LENGTH 18

// 状态机状态定义
typedef enum
{
    RX_STATE_WAIT_HEADER1,
    RX_STATE_WAIT_HEADER2,
    RX_STATE_RECEIVING_DATA
} UART_ReceiverState;

// 接收缓冲区
static uint8_t uart_rx_buffer[UART_RX_FRAME_LENGTH];
static UART_ReceiverState rx_state = RX_STATE_WAIT_HEADER1;
static uint8_t rx_index = 0;
static uint8_t rx_byte = 0;
static UART_HandleTypeDef *receiver_uart = NULL;

// 公共数据定义
uint16_t received_distance = 0;
float received_temperature = 0.0f;
float received_humidity = 0.0f;
uint16_t received_lux = 0;
uint8_t received_gas = 0;

void Receiver_UART_Init(UART_HandleTypeDef *huart)
{
    receiver_uart = huart;
    rx_state = RX_STATE_WAIT_HEADER1;
    HAL_UART_Receive_IT(receiver_uart, &rx_byte, 1); // 开始接收一个字节
}

void Receiver_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart != receiver_uart || receiver_uart == NULL)
        return;

    switch (rx_state)
    {
    case RX_STATE_WAIT_HEADER1:
        if (rx_byte == 0xAA)
        {
            uart_rx_buffer[0] = rx_byte;
            rx_index = 1;
            rx_state = RX_STATE_WAIT_HEADER2;
        }
        break;

    case RX_STATE_WAIT_HEADER2:
        if (rx_byte == 0x55)
        {
            uart_rx_buffer[1] = rx_byte;
            rx_index = 2;
            rx_state = RX_STATE_RECEIVING_DATA;
        }
        else
        {
            rx_state = RX_STATE_WAIT_HEADER1;
        }
        break;

    case RX_STATE_RECEIVING_DATA:
        uart_rx_buffer[rx_index++] = rx_byte;
        if (rx_index >= UART_RX_FRAME_LENGTH)
        {
            // 校验和验证
            uint8_t checksum = 0;
            for (int i = 2; i <= 14; ++i)
                checksum += uart_rx_buffer[i];

            if (checksum == uart_rx_buffer[15] &&
                uart_rx_buffer[16] == '\r' &&
                uart_rx_buffer[17] == '\n')
            {
                received_distance = uart_rx_buffer[2] | (uart_rx_buffer[3] << 8);
                memcpy(&received_temperature, &uart_rx_buffer[4], sizeof(float));
                memcpy(&received_humidity, &uart_rx_buffer[8], sizeof(float));
                received_lux = uart_rx_buffer[12] | (uart_rx_buffer[13] << 8);
                received_gas = uart_rx_buffer[14];

                printf("Received: Distance=%d, Temp=%.2f, Humid=%.2f, Lux=%d, Gas=%d\n",
                       received_distance, received_temperature, received_humidity,
                       received_lux, received_gas);
            }
            else
            {
                printf("Checksum or frame end error. Discarding frame.\n");
            }

            rx_state = RX_STATE_WAIT_HEADER1;
        }
        break;
    }

    // 继续接收下一个字节
    HAL_UART_Receive_IT(receiver_uart, &rx_byte, 1);
}
