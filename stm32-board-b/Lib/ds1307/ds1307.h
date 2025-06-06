#ifndef __DS1307_H
#define __DS1307_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

typedef struct
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t weekday;
    uint8_t day;
    uint8_t month;
    uint8_t year; // 0 ~ 99
} DS1307_Time;

void DS1307_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef DS1307_SetTime(DS1307_Time *time);
HAL_StatusTypeDef DS1307_GetTime(DS1307_Time *time);

#endif
