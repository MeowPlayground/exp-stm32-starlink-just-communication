// page_settings.c
#include "page.h"
#include "meow_oled.h"
#include "meow_font.h"
#include "ds1307.h"
#include "board.h"

#include <stdbool.h>

int8_t temp_high_threshold = 30;     // 温度高阈值
int8_t temp_low_threshold = 10;      // 温度低阈值
int8_t humidity_high_threshold = 80; // 湿度高阈值
int8_t humidity_low_threshold = 20;  // 湿度低阈值
uint16_t light_threshold = 1000;     // 光照阈值

uint8_t temp_hour = 0;
uint8_t temp_minute = 0;

static bool should_update_time = false;

void page_settings_setup(void)
{
    current_point = 0;
    temp_hour = current_time.hours;
    temp_minute = current_time.minutes;
}

void page_settings_loop(void)
{
    if (should_update_time)
    {
        Save_Thresholds_To_Flash(); // 保存阈值到EEPROM
        if (DS1307_SetTime(&current_time) == HAL_OK)
        {
            should_update_time = false;
        }
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // 假设GPIOB_PIN_5连接到LED
    }

    HAL_Delay(50); // 延时100毫秒，避免OLED刷新过快
    Meow_OLED_ClearScreen();
    Meow_OLED_SetFont(&meow_font_cn);
    Meow_OLED_SetCursor(0, 0);
    Meow_OLED_Printf("时间:");

    Meow_OLED_SetCursor(0, 16);
    Meow_OLED_Printf("温度阈值:");

    Meow_OLED_SetCursor(0, 32);
    Meow_OLED_Printf("湿度阈值:");

    Meow_OLED_SetCursor(0, 48);
    Meow_OLED_Printf("光照阈值:");

    Meow_OLED_SetFont(&meow_font_num);
    Meow_OLED_SetCursor(48, 0);
    Meow_OLED_Printf_with_underline(current_point == 0, "%02d", temp_hour);
    Meow_OLED_Printf(":");
    Meow_OLED_Printf_with_underline(current_point == 1, "%02d", temp_minute);
    Meow_OLED_Printf(":%02d", current_time.seconds); // 秒数不修改，显示当前时间秒

    Meow_OLED_SetCursor(64, 16);
    Meow_OLED_Printf_with_underline(current_point == 2, "%d", temp_low_threshold);
    Meow_OLED_Printf("~");
    Meow_OLED_Printf_with_underline(current_point == 3, "%d", temp_high_threshold);
    Meow_OLED_Printf("°C");

    Meow_OLED_SetCursor(64, 32);
    Meow_OLED_Printf_with_underline(current_point == 4, "%d", humidity_low_threshold);
    Meow_OLED_Printf("~");
    Meow_OLED_Printf_with_underline(current_point == 5, "%d", humidity_high_threshold);
    Meow_OLED_Printf("%%");

    Meow_OLED_SetCursor(64, 48);
    Meow_OLED_Printf_with_underline(current_point == 6, "%d", light_threshold);
    Meow_OLED_Printf(" Lx");

    Meow_OLED_Refresh();
}

void handle_settings_event(uint16_t gpio)
{
    if (gpio == ADD_BITTON)
    {
        switch (current_point)
        {
        case 0:
            if (temp_hour < 23)
                temp_hour++;
            break;
        case 1:
            if (temp_minute < 59)
                temp_minute++;
            break;
        case 2:
            if (temp_low_threshold < temp_high_threshold && temp_low_threshold < 99)
                temp_low_threshold++;
            break;
        case 3:
            if (temp_high_threshold < 99)
                temp_high_threshold++;
            if (temp_high_threshold < temp_low_threshold)
                temp_high_threshold = temp_low_threshold;
            break;
        case 4:
            if (humidity_low_threshold < humidity_high_threshold && humidity_low_threshold < 99)
                humidity_low_threshold++;
            break;
        case 5:
            if (humidity_high_threshold < 99)
                humidity_high_threshold++;
            if (humidity_high_threshold < humidity_low_threshold)
                humidity_high_threshold = humidity_low_threshold;
            break;
        case 6:
            if (light_threshold <= 9899)
                light_threshold += 100;
            break;
        }
    }
    else if (gpio == SUB_BITTON)
    {
        switch (current_point)
        {
        case 0:
            if (temp_hour > 0)
                temp_hour--;
            break;
        case 1:
            if (temp_minute > 0)
                temp_minute--;
            break;
        case 2:
            if (temp_low_threshold > -20)
                temp_low_threshold--;
            if (temp_low_threshold > temp_high_threshold)
                temp_low_threshold = temp_high_threshold;
            break;
        case 3:
            if (temp_high_threshold > temp_low_threshold && temp_high_threshold > -20)
                temp_high_threshold--;
            break;
        case 4:
            if (humidity_low_threshold > 0)
                humidity_low_threshold--;
            if (humidity_low_threshold > humidity_high_threshold)
                humidity_low_threshold = humidity_high_threshold;
            break;
        case 5:
            if (humidity_high_threshold > humidity_low_threshold && humidity_high_threshold > 0)
                humidity_high_threshold--;
            break;
        case 6:
            if (light_threshold >= 100)
                light_threshold -= 100;
            break;
        }
    }
    else if (gpio == CONFIRM_BITTON)
    {
        current_time.hours = temp_hour;
        current_time.minutes = temp_minute;
        should_update_time = true; // 设置标志，在主循环中执行

        current_point = (current_point + 1) % 7;
    }
}
