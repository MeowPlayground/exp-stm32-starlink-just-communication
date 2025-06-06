// page_alarm.c
#include "page.h"
#include "meow_oled.h"
#include "meow_font.h"
#include "board.h"

uint8_t alert_type = 0;      // 0: 无警报, 1: 天然气泄漏警报 2:有人靠近警报
uint32_t alert_cooldown = 0; // 警报冷却时间

void page_alarm_setup(void)
{
    Meow_OLED_ClearScreen();
}

void page_alarm_loop(void)
{
    Meow_OLED_ClearScreen();
    Meow_OLED_SetFont(&meow_font_cn);
    Meow_OLED_SetCursor(0, 0);
    if (alert_type == 0)
    {
        Meow_OLED_Printf("无警报");
    }
    else if (alert_type == 1)
    {
        Meow_OLED_Printf("警报: 天然气泄漏");
    }
    else if (alert_type == 2)
    {
        Meow_OLED_Printf("警报: 有人靠近");
    }
    Meow_OLED_Refresh();
}

void handle_alarm_event(uint16_t gpio)
{
    if (gpio == CONFIRM_BITTON) // 确认按钮
    {
        if (alert_type == 1)
        {
            fan_status = 0;
        }
        stop_alert();   // 停止报警
        alert_type = 0; // 清除警报

        alert_cooldown = HAL_GetTick() + 5000; // 设置冷却时间为5秒
    }
    else if (gpio == CANCEL_BITTON) // 取消按钮
    {
        stop_alert(); // 停止报警
        if (alert_type == 1)
        {
            fan_status = 0;
        }
        alert_type = 0; // 清除警报
        stop_alert();   // 停止报警

        alert_cooldown = HAL_GetTick() + 5000; // 设置冷却时间为5秒
    }
}