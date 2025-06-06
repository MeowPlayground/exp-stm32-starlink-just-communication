#include "meow_oled_ui.h"
#include "meow_oled.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

static const MeowFont *currentFont = NULL;
static uint16_t cursor_x = 0;
static uint16_t cursor_y = 0;
static bool text_color = true;
static bool bg_color = false;
static uint8_t text_size = 1;

static int utf8_char_len(const char *s)
{
    unsigned char c = (unsigned char)s[0];
    if ((c & 0x80) == 0x00)
        return 1;
    else if ((c & 0xE0) == 0xC0)
        return 2;
    else if ((c & 0xF0) == 0xE0)
        return 3;
    else if ((c & 0xF8) == 0xF0)
        return 4;
    return 1;
}

void Meow_OLED_SetFont(const MeowFont *font)
{
    currentFont = font;
}

void Meow_OLED_SetCursor(uint16_t x, uint16_t y)
{
    cursor_x = x;
    cursor_y = y;
}

void Meow_OLED_SetTextColor(bool color, bool bg)
{
    text_color = color;
    bg_color = bg;
}

void Meow_OLED_SetTextSize(uint8_t size)
{
    text_size = size;
}

void Meow_OLED_DrawCharUTF8(uint16_t x, uint16_t y,
                            const char *utf8char, int len,
                            bool color, bool bg, uint8_t size)
{
    if (!currentFont)
        return;

    int charIndex = -1;
    const char *p = currentFont->charset;
    for (int i = 0; i < currentFont->charCount; i++)
    {
        int clen = utf8_char_len(p);
        if (clen == len && strncmp(p, utf8char, len) == 0)
        {
            charIndex = i;
            break;
        }
        p += clen;
    }
    if (charIndex < 0)
        return;

    uint16_t totalBits = currentFont->width * currentFont->height;
    uint16_t totalBytes = (totalBits + 7) / 8;
    const uint8_t *charData = &((*currentFont->data)[charIndex * totalBytes]);

    for (uint16_t bitPos = 0; bitPos < totalBits; bitPos++)
    {
        uint8_t row = bitPos / currentFont->width;
        uint8_t col = bitPos % currentFont->width;
        uint16_t byteIdx = bitPos / 8;
        uint8_t bitOff = 7 - (bitPos % 8);
        uint8_t value = (charData[byteIdx] >> bitOff) & 0x01;
        bool drawColor = value ? color : bg;

        for (uint8_t sx = 0; sx < size; sx++)
        {
            for (uint8_t sy = 0; sy < size; sy++)
            {
                Meow_OLED_DrawPixel(
                    x + col * size + sx,
                    y + row * size + sy,
                    drawColor);
            }
        }
    }
}

void Meow_OLED_DrawString(uint16_t x, uint16_t y, const char *str,
                          bool color, bool bg, uint8_t size)
{
    while (*str)
    {
        int len = utf8_char_len(str);
        Meow_OLED_DrawCharUTF8(x, y, str, len, color, bg, size);
        x += currentFont->width * size + size;
        str += len;
    }
}

void Meow_OLED_Printf(const char *format, ...)
{
    char buffer[128];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    Meow_OLED_DrawString(cursor_x, cursor_y, buffer, text_color, bg_color, text_size);

    cursor_x += strlen(buffer) * currentFont->width * text_size + text_size;
}

void Meow_OLED_Printf_with_underline(uint8_t is_draw_underline, const char *format, ...)
{
    char buffer[128];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    Meow_OLED_DrawString(cursor_x, cursor_y, buffer, text_color, bg_color, text_size);

    if (is_draw_underline)
    {
        uint16_t underline_y = cursor_y + currentFont->height * text_size + text_size / 2;
        Meow_OLED_DrawLine(cursor_x, underline_y, cursor_x + strlen(buffer) * currentFont->width * text_size + text_size, underline_y);
    }

    cursor_x += strlen(buffer) * currentFont->width * text_size + text_size;
}

void Meow_OLED_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        Meow_OLED_DrawPixel(x1, y1, text_color);
        if (x1 == x2 && y1 == y2)
            break;
        int err2 = err * 2;
        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}