#include "bh1750.h"
#include "stm32f1xx_hal.h"

// BH1750 初始化函数
void BH1750_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t power_on[] = {BH1750_CMD_POWER_ON};   // 启动传感器
    uint8_t mode[] = {BH1750_CMD_CONT_HRES_MODE}; // 设置连续高分辨率模式

    // 发送启动命令
    if (HAL_I2C_Master_Transmit(hi2c, BH1750_ADDR, power_on, sizeof(power_on), HAL_MAX_DELAY) != HAL_OK)
    {
        // 错误处理
        return;
    }
    HAL_Delay(180); // 等待传感器启动

    // 设置工作模式
    if (HAL_I2C_Master_Transmit(hi2c, BH1750_ADDR, mode, sizeof(mode), HAL_MAX_DELAY) != HAL_OK)
    {
        // 错误处理
        return;
    }
}

// 从 BH1750 读取光照数据
void BH1750_ReadData(I2C_HandleTypeDef *hi2c, uint16_t *lux)
{
    uint8_t data[2];

    // 读取光照数据
    if (HAL_I2C_Master_Receive(hi2c, BH1750_ADDR, data, sizeof(data), HAL_MAX_DELAY) != HAL_OK)
    {
        // 错误处理
        return;
    }

    // 处理数据（合并两个字节，形成16位数值）
    *lux = (data[0] << 8) | data[1];
}
