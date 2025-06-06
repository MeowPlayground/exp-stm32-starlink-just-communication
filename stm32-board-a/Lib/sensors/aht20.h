#ifndef __AHT20_H
#define __AHT20_H

#include "stm32f1xx_hal.h"

// AHT20 7位 I2C 地址（左移1位适配 HAL 函数）
#define AHT20_ADDR (0x38 << 1)

// 函数声明
HAL_StatusTypeDef AHT20_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef AHT20_ReadData(I2C_HandleTypeDef *hi2c, float *temperature, float *humidity);
#endif
