#ifndef __BH1750_H
#define __BH1750_H

#include "stm32f1xx_hal.h"

// BH1750 I2C 地址
#define BH1750_ADDR 0x23 << 1

// BH1750 命令
#define BH1750_CMD_POWER_ON 0x01
#define BH1750_CMD_CONT_HRES_MODE 0x10

// BH1750 初始化函数声明
void BH1750_Init(I2C_HandleTypeDef *hi2c);

// BH1750 数据读取函数声明
void BH1750_ReadData(I2C_HandleTypeDef *hi2c, uint16_t *lux);

#endif /* __BH1750_H */
