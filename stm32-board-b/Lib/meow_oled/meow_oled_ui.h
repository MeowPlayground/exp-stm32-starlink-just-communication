#ifndef MEOW_OLED_UI_H
#define MEOW_OLED_UI_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        const char *charset;     // UTF-8 字符集
        const uint8_t (*data)[]; // 字体位图数据
        uint8_t width;           // 字符宽度
        uint8_t height;          // 字符高度
        uint16_t charCount;      // 字符数量
    } MeowFont;

    void Meow_OLED_SetFont(const MeowFont *font);
    void Meow_OLED_SetCursor(uint16_t x, uint16_t y);
    void Meow_OLED_SetTextColor(bool color, bool bg);
    void Meow_OLED_SetTextSize(uint8_t size);
    void Meow_OLED_DrawCharUTF8(uint16_t x, uint16_t y, const char *utf8char, int len, bool color, bool bg, uint8_t size);
    void Meow_OLED_DrawString(uint16_t x, uint16_t y, const char *str, bool color, bool bg, uint8_t size);
    void Meow_OLED_Printf(const char *format, ...);
    void Meow_OLED_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
    void Meow_OLED_Printf_with_underline(uint8_t is_draw_underline, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif // MEOW_OLED_UI_H
