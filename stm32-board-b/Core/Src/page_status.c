// page_alarm.c
#include "page.h"
#include "meow_oled.h"
#include "meow_font.h"

uint8_t led1_status = 0;  // LED1状态
uint8_t led2_status = 0;  // LED2状态
uint8_t fan_status = 0;   // 风扇状态
uint8_t motor_status = 0; // 电机状态
uint8_t radio_status = 0; // 雷达状态

uint8_t auto_mode = 0; // 自动模式开关，0: 关闭, 1: 开启

void page_status_setup(void)
{
    current_point = 0; // 初始化当前选项为第一个
    Meow_OLED_ClearScreen();
}

void page_status_loop(void)
{
    Meow_OLED_ClearScreen();
    Meow_OLED_SetFont(&meow_font_num);
    Meow_OLED_SetCursor(0, 0);
    Meow_OLED_Printf("LED1:");
    Meow_OLED_SetCursor(64, 0);
    Meow_OLED_Printf("LED2:");
    Meow_OLED_SetFont(&meow_font_cn);
    Meow_OLED_SetCursor(39, 0);
    Meow_OLED_Printf("%s", led1_status ? "开" : "关");
    Meow_OLED_SetCursor(103, 0);
    Meow_OLED_Printf("%s", led2_status ? "开" : "关");

    // 灯，风扇，电机
    Meow_OLED_SetFont(&meow_font_cn);
    Meow_OLED_SetCursor(0, 16);
    Meow_OLED_Printf("风扇:%s", fan_status ? "开" : "关");

    Meow_OLED_SetCursor(0, 32);
    Meow_OLED_Printf("电机:%s", motor_status ? "开" : "关");

    Meow_OLED_SetCursor(0, 48);
    Meow_OLED_Printf("雷达:%s", radio_status ? "开" : "关");

    Meow_OLED_SetCursor(64, 48);
    Meow_OLED_Printf("自动:%s", auto_mode ? "开" : "关");

    if (current_point == 0)
    {
        Meow_OLED_DrawLine(0, 13, 24, 13); // 在第一行下方画一条线
    }
    else if (current_point == 1)
    {
        Meow_OLED_DrawLine(64, 13, 88, 13); // 在第二行下方画一条线
    }
    else if (current_point == 2)
    {
        Meow_OLED_DrawLine(0, 29, 24, 29); // 在第三行下方画一条线
    }
    else if (current_point == 3)
    {
        Meow_OLED_DrawLine(0, 45, 24, 45); // 在第四行下方画一条线
    }
    else if (current_point == 4)
    {
        Meow_OLED_DrawLine(0, 61, 24, 61); // 在第五行下方画一条线
    }
    else if (current_point == 5)
    {
        Meow_OLED_DrawLine(64, 61, 88, 61); // 在第六行下方画一条线
    }
    Meow_OLED_Refresh();
}

void handle_status_event(uint16_t gpio)
{
    if (gpio == GPIO_PIN_3)
    {
        current_point++;
        if (current_point > 5)
        {
            current_point = 0; // 重置到第一个选项
        }
    }
    else if (gpio == GPIO_PIN_4)
    {
        current_point--;
        if (current_point < 0)
        {
            current_point = 5; // 重置到最后一个选项
        }
    }
    else if (gpio == GPIO_PIN_6)
    {
        switch (current_point)
        {
        case 0:
            led1_status = !led1_status; // 切换LED1状态
            break;
        case 1:
            led2_status = !led2_status; // 切换LED2状态
            break;
        case 2:
            fan_status = !fan_status; // 切换灯状态
            break;
        case 3:
            motor_status = !motor_status; // 切换风扇状态
            break;
        case 4:
            radio_status = !radio_status; // 切换电机状态
            break;
        case 5:
            auto_mode = !auto_mode; // 切换自动模式状态
            break;
        }
    }
}