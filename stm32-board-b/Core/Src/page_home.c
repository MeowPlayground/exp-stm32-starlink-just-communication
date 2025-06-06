// page_home.c
#include "page.h"
#include "meow_oled.h"
#include "meow_font.h"
#include "receiver.h"
#include "ds1307.h"

DS1307_Time current_time = {0, 0, 0}; // 当前时间

void page_home_setup(void)
{
    Meow_OLED_ClearScreen();
}

void page_home_loop(void)
{
    // 页面主逻辑
    Meow_OLED_ClearScreen();
    // 显示当前时间
    Meow_OLED_SetFont(&meow_font_cn);
    Meow_OLED_SetCursor(0, 0);
    Meow_OLED_Printf("时间:");
    Meow_OLED_SetCursor(0, 16);
    Meow_OLED_Printf("温度:");
    Meow_OLED_SetCursor(0, 32);
    Meow_OLED_Printf("湿度:");
    Meow_OLED_SetCursor(0, 48);
    Meow_OLED_Printf("光照:", received_lux);
    Meow_OLED_SetFont(&meow_font_num);

    Meow_OLED_SetFont(&meow_font_num);
    Meow_OLED_SetCursor(36, 0);
    Meow_OLED_Printf(" %02d:%02d:%02d", current_time.hours, current_time.minutes, current_time.seconds);
    Meow_OLED_SetCursor(36, 16);
    Meow_OLED_Printf(" %.1f°C ", received_temperature);
    Meow_OLED_SetCursor(36, 32);
    Meow_OLED_Printf(" %.1f %% ", received_humidity);
    Meow_OLED_SetCursor(36, 48);
    Meow_OLED_Printf(" %d Lx", received_lux);
    DS1307_GetTime(&current_time);
    // LED1 LED2

    Meow_OLED_Refresh();

    HAL_Delay(10);
}
