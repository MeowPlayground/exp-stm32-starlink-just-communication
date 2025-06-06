#include "ds1307.h"
#include "stm32f1xx_hal_rtc.h"
#include "rtc.h"

#define DS1307_ADDRESS (0x68 << 1)
#define DS1307_REG_TIME 0x00

#define DS1307_SECONDS 0
#define DS1307_MINUTES 1
#define DS1307_HOURS 2
#define DS1307_WEEKDAY 3
#define DS1307_DAY 4
#define DS1307_MONTH 5
#define DS1307_YEAR 6

#define DS1307_VERIFY_WRITE 1

static I2C_HandleTypeDef *ds1307_i2c;

static uint8_t bcd2dec(uint8_t val)
{
    return ((val >> 4) * 10) + (val & 0x0F);
}

static uint8_t dec2bcd(uint8_t val)
{
    return ((val / 10) << 4) | (val % 10);
}

static HAL_StatusTypeDef DS1307_CheckBusReady(void)
{
    uint32_t tickstart = HAL_GetTick();
    while (HAL_I2C_GetState(ds1307_i2c) != HAL_I2C_STATE_READY)
    {
        if ((HAL_GetTick() - tickstart) > 100)
            return HAL_ERROR;
    }
    return HAL_OK;
}

// 🟢 设置 STM32 RTC 时间（适配 STM32F1，无 DayLightSaving 和 StoreOperation）
static void RTC_SetFromDS1307(const DS1307_Time *time)
{
    RTC_TimeTypeDef sTime = {0};
    sTime.Hours = time->hours;
    sTime.Minutes = time->minutes;
    sTime.Seconds = time->seconds;

    RTC_DateTypeDef sDate = {0};
    sDate.WeekDay = time->weekday;
    sDate.Month = time->month;
    sDate.Date = time->day;
    sDate.Year = time->year;

    HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

// 🟢 从 STM32 RTC 获取时间到 DS1307_Time
static void RTC_GetToDS1307(DS1307_Time *time)
{
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;

    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    time->seconds = sTime.Seconds;
    time->minutes = sTime.Minutes;
    time->hours = sTime.Hours;
    time->weekday = sDate.WeekDay;
    time->day = sDate.Date;
    time->month = sDate.Month;
    time->year = sDate.Year;
}

void DS1307_Init(I2C_HandleTypeDef *hi2c)
{
    ds1307_i2c = hi2c;

    // 从 DS1307 读取时间，设置 STM32 RTC
    uint8_t reg = DS1307_REG_TIME;
    uint8_t data[7];

    if (DS1307_CheckBusReady() == HAL_OK &&
        HAL_I2C_Master_Transmit(ds1307_i2c, DS1307_ADDRESS, &reg, 1, 1000) == HAL_OK &&
        HAL_I2C_Master_Receive(ds1307_i2c, DS1307_ADDRESS, data, 7, 1000) == HAL_OK)
    {
        DS1307_Time time = {
            .seconds = bcd2dec(data[DS1307_SECONDS] & 0x7F),
            .minutes = bcd2dec(data[DS1307_MINUTES]),
            .hours = bcd2dec(data[DS1307_HOURS] & 0x3F),
            .weekday = bcd2dec(data[DS1307_WEEKDAY]),
            .day = bcd2dec(data[DS1307_DAY]),
            .month = bcd2dec(data[DS1307_MONTH]),
            .year = bcd2dec(data[DS1307_YEAR])};

        RTC_SetFromDS1307(&time); // 设置 STM32 内置 RTC
    }
}

HAL_StatusTypeDef DS1307_SetTime(DS1307_Time *time)
{
    if (DS1307_CheckBusReady() != HAL_OK)
        return HAL_ERROR;

    // 1️⃣ 设置 STM32 RTC
    RTC_SetFromDS1307(time);

    // 2️⃣ 写入 DS1307
    uint8_t data[8];
    data[0] = DS1307_REG_TIME;
    data[1] = dec2bcd(time->seconds) & 0x7F;
    data[2] = dec2bcd(time->minutes);
    data[3] = dec2bcd(time->hours);
    data[4] = dec2bcd(time->weekday);
    data[5] = dec2bcd(time->day);
    data[6] = dec2bcd(time->month);
    data[7] = dec2bcd(time->year);

    if (HAL_I2C_Master_Transmit(ds1307_i2c, DS1307_ADDRESS, data, 8, 1000) != HAL_OK)
        return HAL_ERROR;

#if DS1307_VERIFY_WRITE
    uint8_t reg = DS1307_REG_TIME;
    uint8_t read[7];

    if (HAL_I2C_Master_Transmit(ds1307_i2c, DS1307_ADDRESS, &reg, 1, 1000) != HAL_OK)
        return HAL_ERROR;
    if (HAL_I2C_Master_Receive(ds1307_i2c, DS1307_ADDRESS, read, 7, 1000) != HAL_OK)
        return HAL_ERROR;

    if (
        bcd2dec(read[DS1307_SECONDS] & 0x7F) != time->seconds ||
        bcd2dec(read[DS1307_MINUTES]) != time->minutes ||
        bcd2dec(read[DS1307_HOURS] & 0x3F) != time->hours ||
        bcd2dec(read[DS1307_WEEKDAY]) != time->weekday ||
        bcd2dec(read[DS1307_DAY]) != time->day ||
        bcd2dec(read[DS1307_MONTH]) != time->month ||
        bcd2dec(read[DS1307_YEAR]) != time->year)
    {
        return HAL_ERROR;
    }
#endif

    return HAL_OK;
}

HAL_StatusTypeDef DS1307_GetTime(DS1307_Time *time)
{
    RTC_GetToDS1307(time); // 实际从 STM32 RTC 获取
    return HAL_OK;
}
