#include "reciver.h"
#include <stdio.h>
#include <stdint.h>

#define UART_RX_FRAME_LENGTH 9

typedef enum {
    WAIT_FOR_HEAD1,
    WAIT_FOR_HEAD2,
    WAIT_FOR_DATA1,
    WAIT_FOR_DATA2,
    WAIT_FOR_DATA3,
    WAIT_FOR_DATA4,
    WAIT_FOR_CHECKSUM,
    WAIT_FOR_TAIL1,
    WAIT_FOR_TAIL2
} ReceiverState;

static ReceiverState rx_state = WAIT_FOR_HEAD1;
static uint8_t uart_rx_buffer[UART_RX_FRAME_LENGTH];
static uint8_t rx_index = 0;

static UART_HandleTypeDef *receiver_uart = NULL;
static uint8_t rx_byte = 0;

uint8_t led1_status = 0;
uint8_t led2_status = 0;
uint8_t fan_status = 0;
uint8_t motor_status = 0;

void Receiver_UART_Init(UART_HandleTypeDef *huart)
{
    receiver_uart = huart;
    rx_state = WAIT_FOR_HEAD1;
    rx_index = 0;
    HAL_UART_Receive_IT(receiver_uart, &rx_byte, 1);  // 改为单字节缓存
}

static void Receiver_Reset()
{
    rx_state = WAIT_FOR_HEAD1;
    rx_index = 0;
}

void Receiver_Process_Byte(uint8_t byte)
{
    switch (rx_state)
    {
        case WAIT_FOR_HEAD1:
            if (byte == 0xAA) {
                uart_rx_buffer[rx_index++] = byte;
                rx_state = WAIT_FOR_HEAD2;
            }
            break;

        case WAIT_FOR_HEAD2:
            if (byte == 0x55) {
                uart_rx_buffer[rx_index++] = byte;
                rx_state = WAIT_FOR_DATA1;
            } else {
                Receiver_Reset();  // 错误则重置
            }
            break;

        case WAIT_FOR_DATA1:
        case WAIT_FOR_DATA2:
        case WAIT_FOR_DATA3:
        case WAIT_FOR_DATA4:
        case WAIT_FOR_CHECKSUM:
            uart_rx_buffer[rx_index++] = byte;
            rx_state++;
            break;

        case WAIT_FOR_TAIL1:
            if (byte == 0x0D) {
                uart_rx_buffer[rx_index++] = byte;
                rx_state = WAIT_FOR_TAIL2;
            } else {
                printf("尾部第1字节错误，收到: 0x%02X\n", byte);
                Receiver_Reset();
            }
            break;

        case WAIT_FOR_TAIL2:
            if (byte == 0x0A) {
                uart_rx_buffer[rx_index++] = byte;

                // 计算校验和：data1~data4 (index 2~5)
                uint8_t calc_checksum = 0;
                for (int i = 2; i <= 5; ++i)
                    calc_checksum += uart_rx_buffer[i];

                if (calc_checksum == uart_rx_buffer[6]) {
                    led1_status = uart_rx_buffer[2];
                    led2_status = uart_rx_buffer[3];
                    fan_status = uart_rx_buffer[4];
                    motor_status = uart_rx_buffer[5];

                    printf("✅ 接收成功：LED1=%d, LED2=%d, FAN=%d, MOTOR=%d\n",
                           led1_status, led2_status, fan_status, motor_status);
                } else {
                    printf("⚠️ 接收数据：LED1=%d, LED2=%d, FAN=%d, MOTOR=%d\n",
                           uart_rx_buffer[2], uart_rx_buffer[3],
                           uart_rx_buffer[4], uart_rx_buffer[5]);
                    printf("❌ 校验错误：计算=0x%02X, 实际=0x%02X\n",
                           calc_checksum, uart_rx_buffer[6]);
                }
            } else {
                printf("尾部第2字节错误，收到: 0x%02X\n", byte);
            }

            // 无论成功失败都重置
            Receiver_Reset();
            break;
    }
}

void Receiver_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart != receiver_uart || receiver_uart == NULL)
        return;

    Receiver_Process_Byte(rx_byte);
    HAL_UART_Receive_IT(receiver_uart, &rx_byte, 1);  // 继续接收1字节
}
