#ifndef MEOW_OLED_H
#define MEOW_OLED_H

#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define MEOW_OLED_WIDTH 128
#define MEOW_OLED_HEIGHT 64

    // 传入 I2C 句柄并初始化 OLED
    void Meow_OLED_Init(I2C_HandleTypeDef *hi2c);

    // 画点、线、矩形等
    void Meow_OLED_DrawPixel(uint8_t x, uint8_t y, bool on);
    void Meow_OLED_ClearScreen(void);
    void Meow_OLED_Refresh(void);

#ifdef __cplusplus
}
#endif

#endif // MEOW_OLED_H
