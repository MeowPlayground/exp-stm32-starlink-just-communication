#include "aht20.h"
#include "stm32f1xx_hal.h"
#include "stdint.h"
#include "string.h"

// AHT20 指令
#define AHT20_CMD_INIT 0xBE
#define AHT20_CMD_TRIGGER 0xAC
#define AHT20_CMD_SOFTRESET 0xBA

// 等待时间（单位：ms）
#define AHT20_MEASUREMENT_DELAY 80

// 初始化函数
HAL_StatusTypeDef AHT20_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t init_cmd[3] = {AHT20_CMD_INIT, 0x08, 0x00};
    HAL_StatusTypeDef ret;
    ret = HAL_I2C_Master_Transmit(hi2c, AHT20_ADDR, init_cmd, 3, HAL_MAX_DELAY);
    if (ret != HAL_OK)
        return ret;
    HAL_Delay(10); // 等待初始化完成
    return HAL_OK;
}

HAL_StatusTypeDef AHT20_ReadData(I2C_HandleTypeDef *hi2c, float *temperature, float *humidity)
{
    uint8_t trigger_cmd[3] = {AHT20_CMD_TRIGGER, 0x33, 0x00};
    HAL_StatusTypeDef ret;

    // 触发测量
    ret = HAL_I2C_Master_Transmit(hi2c, AHT20_ADDR, trigger_cmd, 3, HAL_MAX_DELAY);
    if (ret != HAL_OK)
        return ret;

    HAL_Delay(AHT20_MEASUREMENT_DELAY); // 等待测量完成

    uint8_t rx_data[6] = {0};
    ret = HAL_I2C_Master_Receive(hi2c, AHT20_ADDR, rx_data, 6, HAL_MAX_DELAY);
    if (ret != HAL_OK)
        return ret;

    // 检查忙碌位
    if (rx_data[0] & 0x80)
        return HAL_ERROR;

    // 提取湿度（20-bit）
    uint32_t hum_raw = ((uint32_t)rx_data[1] << 12) |
                       ((uint32_t)rx_data[2] << 4) |
                       ((rx_data[3] & 0xF0) >> 4);

    // 提取温度（20-bit）
    uint32_t temp_raw = ((uint32_t)(rx_data[3] & 0x0F) << 16) |
                        ((uint32_t)rx_data[4] << 8) |
                        (uint32_t)rx_data[5];

    // 转换为实际值（原始值 / 2^20）
    *humidity = ((float)hum_raw * 100.0f) / 1048576.0f;
    *temperature = ((float)temp_raw * 200.0f) / 1048576.0f - 50.0f;

    return HAL_OK;
}
