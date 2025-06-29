/*@注意：此文件由Image2Display生成 */
/*@Size: 8x12, Char: 122,Data per char: 12 */

#include "meow_oled_ui.h"
#include <stdint.h>
/*@注意：此文件由Image2Display生成 */
/*@Size: 16x24, Char: 62,Data per char: 48 */
const char charset1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

const uint8_t fonts1[] = {
    /* A */
    0x00,
    0x00,
    0x03,
    0x80,
    0x03,
    0xC0,
    0x07,
    0xC0,
    0x06,
    0xC0,
    0x06,
    0xE0,
    0x0E,
    0x60,
    0x0C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x30,
    0x18,
    0x38,
    0x3F,
    0xF8,
    0x3F,
    0xFC,
    0x70,
    0x1C,
    0x70,
    0x0C,
    0x60,
    0x0E,
    0xE0,
    0x0E,
    0xE0,
    0x07,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* B */
    0x00,
    0x00,
    0x1F,
    0xE0,
    0x1F,
    0xF0,
    0x1C,
    0x78,
    0x1C,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x70,
    0x1F,
    0xE0,
    0x1F,
    0xF0,
    0x1C,
    0x78,
    0x1C,
    0x18,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x18,
    0x1C,
    0x78,
    0x1F,
    0xF0,
    0x1F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* C */
    0x00,
    0x00,
    0x01,
    0xFE,
    0x07,
    0xFE,
    0x0F,
    0x8E,
    0x1E,
    0x00,
    0x1C,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x30,
    0x00,
    0x30,
    0x00,
    0x30,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x18,
    0x00,
    0x1C,
    0x00,
    0x0F,
    0x0E,
    0x07,
    0xFE,
    0x03,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* D */
    0x00,
    0x00,
    0x3F,
    0xE0,
    0x3F,
    0xF8,
    0x38,
    0x7C,
    0x38,
    0x1E,
    0x38,
    0x0E,
    0x38,
    0x07,
    0x38,
    0x07,
    0x38,
    0x07,
    0x38,
    0x07,
    0x38,
    0x07,
    0x38,
    0x07,
    0x38,
    0x06,
    0x38,
    0x0E,
    0x38,
    0x1C,
    0x38,
    0x7C,
    0x3F,
    0xF0,
    0x3F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* E */
    0x00,
    0x00,
    0x0F,
    0xF8,
    0x0F,
    0xF8,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0F,
    0xF8,
    0x0F,
    0xF8,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0F,
    0xFC,
    0x0F,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* F */
    0x00,
    0x00,
    0x0F,
    0xF8,
    0x0F,
    0xF8,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0F,
    0xF8,
    0x0F,
    0xF8,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* G */
    0x00,
    0x00,
    0x03,
    0xFC,
    0x0F,
    0xFE,
    0x1F,
    0x0E,
    0x3C,
    0x00,
    0x38,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0x60,
    0x00,
    0x60,
    0x7E,
    0x60,
    0x7E,
    0x70,
    0x0E,
    0x70,
    0x0E,
    0x30,
    0x0E,
    0x38,
    0x0E,
    0x1F,
    0x1E,
    0x0F,
    0xFE,
    0x07,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* H */
    0x00,
    0x00,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x7F,
    0xFC,
    0x7F,
    0xFC,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* I */
    0x00,
    0x00,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* J */
    0x00,
    0x00,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xC0,
    0x01,
    0xC0,
    0x0F,
    0x80,
    0x0F,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* K */
    0x00,
    0x00,
    0x1C,
    0x1C,
    0x1C,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x70,
    0x1C,
    0xE0,
    0x1D,
    0xC0,
    0x1F,
    0x80,
    0x1F,
    0x00,
    0x1F,
    0x00,
    0x1F,
    0x80,
    0x1F,
    0x80,
    0x1D,
    0xC0,
    0x1C,
    0xE0,
    0x1C,
    0x70,
    0x1C,
    0x38,
    0x1C,
    0x1C,
    0x1C,
    0x1E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* L */
    0x00,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0F,
    0xF8,
    0x0F,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* M */
    0x00,
    0x00,
    0xE0,
    0x0F,
    0xF0,
    0x0F,
    0xF0,
    0x1F,
    0xF8,
    0x1F,
    0xD8,
    0x3F,
    0xDC,
    0x3F,
    0xEC,
    0x77,
    0xEE,
    0x67,
    0xE6,
    0xE7,
    0xE7,
    0xC7,
    0xE3,
    0xC7,
    0xE3,
    0x87,
    0xE1,
    0x87,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* N */
    0x00,
    0x00,
    0x70,
    0x0E,
    0x78,
    0x0E,
    0x7C,
    0x0E,
    0x7C,
    0x0E,
    0x6E,
    0x0E,
    0x76,
    0x0E,
    0x77,
    0x0E,
    0x73,
    0x8E,
    0x71,
    0x8E,
    0x71,
    0xCE,
    0x70,
    0xEE,
    0x70,
    0xEE,
    0x70,
    0x7E,
    0x70,
    0x3E,
    0x70,
    0x3E,
    0x70,
    0x1E,
    0x70,
    0x0E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* O */
    0x00,
    0x00,
    0x0F,
    0xF0,
    0x1F,
    0xF8,
    0x3C,
    0x3C,
    0x70,
    0x0E,
    0x60,
    0x06,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0x60,
    0x06,
    0x70,
    0x0E,
    0x3C,
    0x3C,
    0x1F,
    0xF8,
    0x0F,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* P */
    0x00,
    0x00,
    0x1F,
    0xE0,
    0x1F,
    0xF0,
    0x1C,
    0x78,
    0x1C,
    0x18,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x18,
    0x1C,
    0x78,
    0x1F,
    0xF0,
    0x1F,
    0xE0,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* Q */
    0x00,
    0x00,
    0x0F,
    0xF0,
    0x1F,
    0xF8,
    0x3C,
    0x3C,
    0x70,
    0x0E,
    0x60,
    0x06,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xE0,
    0x07,
    0xE0,
    0x07,
    0x60,
    0x06,
    0x70,
    0x0E,
    0x3C,
    0x3C,
    0x1F,
    0xF8,
    0x0F,
    0xF0,
    0x00,
    0xE0,
    0x00,
    0x70,
    0x00,
    0x38,
    0x00,
    0x1F,
    0x00,
    0x0F,
    0x00,
    0x00,

    /* R */
    0x00,
    0x00,
    0x1F,
    0xE0,
    0x1F,
    0xF0,
    0x1C,
    0x38,
    0x1C,
    0x18,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x18,
    0x1C,
    0x78,
    0x1F,
    0xF0,
    0x1F,
    0xC0,
    0x1C,
    0xE0,
    0x1C,
    0x70,
    0x1C,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x1C,
    0x1C,
    0x0E,
    0x1C,
    0x0E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* S */
    0x00,
    0x00,
    0x03,
    0xF8,
    0x07,
    0xF8,
    0x0E,
    0x18,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x0E,
    0x00,
    0x07,
    0x80,
    0x03,
    0xE0,
    0x00,
    0xF0,
    0x00,
    0x38,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x1C,
    0x38,
    0x1F,
    0xF8,
    0x0F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* T */
    0x00,
    0x00,
    0x3F,
    0xFC,
    0x3F,
    0xFC,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* U */
    0x00,
    0x00,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x30,
    0x0E,
    0x38,
    0x0E,
    0x38,
    0x1C,
    0x1E,
    0x3C,
    0x1F,
    0xF8,
    0x07,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* V */
    0x00,
    0x00,
    0x70,
    0x07,
    0x70,
    0x07,
    0x30,
    0x06,
    0x38,
    0x0E,
    0x38,
    0x0E,
    0x18,
    0x0C,
    0x1C,
    0x1C,
    0x0C,
    0x18,
    0x0E,
    0x38,
    0x0E,
    0x38,
    0x06,
    0x30,
    0x07,
    0x70,
    0x07,
    0x70,
    0x03,
    0xE0,
    0x03,
    0xE0,
    0x03,
    0xC0,
    0x01,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* W */
    0x00,
    0x00,
    0x01,
    0xC0,
    0x01,
    0xC0,
    0x03,
    0xC0,
    0x83,
    0xE0,
    0x83,
    0xE0,
    0x83,
    0x61,
    0x87,
    0x61,
    0xC6,
    0x71,
    0xC6,
    0x71,
    0xCE,
    0x33,
    0xCE,
    0x3B,
    0xEC,
    0x3B,
    0xEC,
    0x1B,
    0x7C,
    0x1F,
    0x78,
    0x1E,
    0x78,
    0x1E,
    0x38,
    0x0E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* X */
    0x00,
    0x00,
    0x38,
    0x0E,
    0x38,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x38,
    0x0E,
    0x30,
    0x07,
    0x70,
    0x07,
    0xE0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xE0,
    0x07,
    0xE0,
    0x06,
    0x70,
    0x0E,
    0x30,
    0x1C,
    0x38,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x70,
    0x0E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* Y */
    0x00,
    0x00,
    0x70,
    0x0C,
    0x70,
    0x1C,
    0x38,
    0x18,
    0x38,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x70,
    0x0E,
    0x60,
    0x0E,
    0xE0,
    0x07,
    0xC0,
    0x07,
    0xC0,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* Z */
    0x00,
    0x00,
    0x3F,
    0xFC,
    0x3F,
    0xFC,
    0x00,
    0x18,
    0x00,
    0x30,
    0x00,
    0x70,
    0x00,
    0xE0,
    0x00,
    0xC0,
    0x01,
    0xC0,
    0x03,
    0x80,
    0x03,
    0x00,
    0x07,
    0x00,
    0x0E,
    0x00,
    0x0C,
    0x00,
    0x1C,
    0x00,
    0x38,
    0x00,
    0x3F,
    0xFC,
    0x7F,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* a */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xE0,
    0x0F,
    0xF0,
    0x0C,
    0x78,
    0x00,
    0x38,
    0x00,
    0x38,
    0x03,
    0xF8,
    0x0F,
    0xF8,
    0x1F,
    0xB8,
    0x18,
    0x38,
    0x1C,
    0x78,
    0x1F,
    0xF8,
    0x0F,
    0xB8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* b */
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x19,
    0xF0,
    0x1B,
    0xF8,
    0x1E,
    0x3C,
    0x1C,
    0x1C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x1C,
    0x1C,
    0x1E,
    0x38,
    0x1F,
    0xF8,
    0x1B,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* c */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0xF0,
    0x07,
    0xF8,
    0x0F,
    0x18,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x0F,
    0x18,
    0x07,
    0xF8,
    0x03,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* d */
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x07,
    0xDC,
    0x0F,
    0xFC,
    0x1C,
    0x7C,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x30,
    0x1C,
    0x38,
    0x1C,
    0x38,
    0x3C,
    0x1C,
    0x7C,
    0x1F,
    0xFC,
    0x0F,
    0xDC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* e */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0xE0,
    0x07,
    0xF0,
    0x0E,
    0x38,
    0x1C,
    0x1C,
    0x18,
    0x1C,
    0x1F,
    0xFC,
    0x1F,
    0xFC,
    0x18,
    0x00,
    0x1C,
    0x00,
    0x0E,
    0x18,
    0x0F,
    0xF8,
    0x03,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* f */
    0x00,
    0xF0,
    0x01,
    0xF0,
    0x01,
    0xC0,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x0F,
    0xF0,
    0x0F,
    0xF0,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* g */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xDC,
    0x0F,
    0xFC,
    0x1C,
    0x7C,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x30,
    0x1C,
    0x38,
    0x1C,
    0x38,
    0x3C,
    0x1C,
    0x7C,
    0x1F,
    0xFC,
    0x0F,
    0xDC,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x38,
    0x18,
    0xF8,
    0x1F,
    0xF0,
    0x1F,
    0xC0,

    /* h */
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x1B,
    0xE0,
    0x1F,
    0xF0,
    0x1E,
    0x78,
    0x1C,
    0x38,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* i */
    0x00,
    0x00,
    0x03,
    0x80,
    0x03,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x01,
    0x80,
    0x01,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* j */
    0x00,
    0x00,
    0x01,
    0x80,
    0x01,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x01,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x37,
    0x00,
    0x3F,
    0x00,
    0x1E,
    0x00,

    /* k */
    0x0C,
    0x00,
    0x0C,
    0x00,
    0x0C,
    0x00,
    0x0C,
    0x00,
    0x0C,
    0x00,
    0x0C,
    0x00,
    0x0C,
    0x38,
    0x0C,
    0x70,
    0x0C,
    0xE0,
    0x0D,
    0xC0,
    0x0D,
    0x80,
    0x0F,
    0x00,
    0x0F,
    0x80,
    0x0D,
    0xC0,
    0x0C,
    0xE0,
    0x0C,
    0x70,
    0x0C,
    0x38,
    0x0C,
    0x1C,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* l */
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x01,
    0x80,
    0x01,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* m */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xDF,
    0x3E,
    0xFF,
    0xFF,
    0xF3,
    0xE7,
    0xE1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0xC1,
    0xC3,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* n */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1B,
    0xE0,
    0x1F,
    0xF0,
    0x1E,
    0x78,
    0x1C,
    0x38,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* o */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xE0,
    0x0F,
    0xF8,
    0x1E,
    0x38,
    0x38,
    0x1C,
    0x38,
    0x0C,
    0x30,
    0x0C,
    0x30,
    0x0C,
    0x38,
    0x0C,
    0x38,
    0x1C,
    0x1E,
    0x38,
    0x0F,
    0xF0,
    0x07,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* p */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x19,
    0xF0,
    0x1B,
    0xF8,
    0x1E,
    0x3C,
    0x1C,
    0x1C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x1C,
    0x1C,
    0x1E,
    0x38,
    0x1F,
    0xF8,
    0x1B,
    0xE0,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,

    /* q */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xDC,
    0x0F,
    0xFC,
    0x1C,
    0x7C,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x30,
    0x1C,
    0x38,
    0x1C,
    0x38,
    0x3C,
    0x1C,
    0x7C,
    0x1F,
    0xFC,
    0x0F,
    0xDC,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,

    /* r */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0x70,
    0x03,
    0xF8,
    0x03,
    0xC0,
    0x03,
    0x80,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* s */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0xF0,
    0x07,
    0xF0,
    0x0E,
    0x30,
    0x0E,
    0x00,
    0x0F,
    0x00,
    0x07,
    0xC0,
    0x03,
    0xE0,
    0x00,
    0x70,
    0x00,
    0x38,
    0x0C,
    0x70,
    0x0F,
    0xF0,
    0x0F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* t */
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x0F,
    0xF0,
    0x0F,
    0xF0,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x80,
    0x01,
    0xF0,
    0x01,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* u */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x38,
    0x18,
    0x38,
    0x1C,
    0x78,
    0x1F,
    0xF8,
    0x0F,
    0xB8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* v */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x1C,
    0x38,
    0x18,
    0x18,
    0x38,
    0x1C,
    0x30,
    0x1C,
    0x30,
    0x0C,
    0x70,
    0x0E,
    0x60,
    0x06,
    0xE0,
    0x06,
    0xC0,
    0x07,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* w */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC1,
    0x83,
    0xC3,
    0xC3,
    0xC3,
    0xC7,
    0xC3,
    0xC7,
    0xE6,
    0xC6,
    0x66,
    0xE6,
    0x66,
    0x6E,
    0x7C,
    0x6C,
    0x7C,
    0x7C,
    0x3C,
    0x3C,
    0x3C,
    0x38,
    0x38,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* x */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x38,
    0x38,
    0x1C,
    0x30,
    0x0C,
    0x70,
    0x0E,
    0xE0,
    0x07,
    0xC0,
    0x03,
    0x80,
    0x03,
    0x80,
    0x07,
    0xC0,
    0x0E,
    0xE0,
    0x0C,
    0x60,
    0x1C,
    0x70,
    0x38,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* y */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x38,
    0x1C,
    0x38,
    0x18,
    0x18,
    0x38,
    0x1C,
    0x38,
    0x1C,
    0x30,
    0x0C,
    0x70,
    0x0E,
    0x60,
    0x06,
    0x60,
    0x07,
    0xE0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0x80,
    0x03,
    0x80,
    0x03,
    0x00,
    0x07,
    0x00,
    0x0F,
    0x00,
    0x3E,
    0x00,
    0x3C,
    0x00,

    /* z */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x0F,
    0xFC,
    0x0F,
    0xF8,
    0x00,
    0x30,
    0x00,
    0x60,
    0x00,
    0xE0,
    0x00,
    0xC0,
    0x01,
    0x80,
    0x03,
    0x00,
    0x07,
    0x00,
    0x0E,
    0x00,
    0x0F,
    0xFC,
    0x1F,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 0 */
    0x00,
    0x00,
    0x03,
    0xE0,
    0x07,
    0xF0,
    0x0E,
    0x38,
    0x0C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x0C,
    0x18,
    0x1C,
    0x1C,
    0x1C,
    0x1C,
    0x18,
    0x0E,
    0x38,
    0x07,
    0xF0,
    0x03,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 1 */
    0x00,
    0x00,
    0x00,
    0x60,
    0x01,
    0xE0,
    0x07,
    0xE0,
    0x0F,
    0xE0,
    0x0E,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 2 */
    0x00,
    0x00,
    0x07,
    0xE0,
    0x0F,
    0xF0,
    0x0E,
    0x78,
    0x08,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x38,
    0x00,
    0x30,
    0x00,
    0x70,
    0x00,
    0xE0,
    0x03,
    0x80,
    0x07,
    0x00,
    0x0E,
    0x00,
    0x0C,
    0x00,
    0x1C,
    0x00,
    0x1F,
    0xFC,
    0x1F,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 3 */
    0x00,
    0x00,
    0x0F,
    0xE0,
    0x0F,
    0xF0,
    0x0C,
    0x78,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x30,
    0x00,
    0xF0,
    0x07,
    0xE0,
    0x07,
    0xF0,
    0x00,
    0x78,
    0x00,
    0x38,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x38,
    0x18,
    0x78,
    0x1F,
    0xF0,
    0x0F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 4 */
    0x00,
    0x00,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x01,
    0xB0,
    0x03,
    0xB0,
    0x03,
    0x30,
    0x06,
    0x30,
    0x0E,
    0x30,
    0x1C,
    0x30,
    0x38,
    0x30,
    0x3F,
    0xFE,
    0x3F,
    0xFE,
    0x00,
    0x30,
    0x00,
    0x30,
    0x00,
    0x30,
    0x00,
    0x30,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 5 */
    0x00,
    0x00,
    0x0F,
    0xF8,
    0x0F,
    0xF8,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x0F,
    0xE0,
    0x0F,
    0xF0,
    0x00,
    0x78,
    0x00,
    0x18,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x38,
    0x0C,
    0x78,
    0x0F,
    0xF0,
    0x0F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 6 */
    0x00,
    0x00,
    0x01,
    0xF8,
    0x03,
    0xF8,
    0x07,
    0x88,
    0x0E,
    0x00,
    0x0C,
    0x00,
    0x0C,
    0x00,
    0x1F,
    0xF0,
    0x1F,
    0xF8,
    0x1E,
    0x3C,
    0x1C,
    0x1C,
    0x1C,
    0x0C,
    0x1C,
    0x0C,
    0x1C,
    0x0C,
    0x0C,
    0x1C,
    0x0F,
    0x38,
    0x07,
    0xF8,
    0x03,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 7 */
    0x00,
    0x00,
    0x1F,
    0xFC,
    0x1F,
    0xFC,
    0x00,
    0x18,
    0x00,
    0x38,
    0x00,
    0x30,
    0x00,
    0x70,
    0x00,
    0x60,
    0x00,
    0x60,
    0x00,
    0xE0,
    0x00,
    0xC0,
    0x01,
    0xC0,
    0x01,
    0x80,
    0x01,
    0x80,
    0x03,
    0x80,
    0x03,
    0x00,
    0x03,
    0x00,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 8 */
    0x00,
    0x00,
    0x03,
    0xE0,
    0x07,
    0xF0,
    0x0E,
    0x38,
    0x0C,
    0x18,
    0x1C,
    0x1C,
    0x0C,
    0x18,
    0x0E,
    0x38,
    0x07,
    0xF0,
    0x07,
    0xF0,
    0x0E,
    0x38,
    0x1C,
    0x1C,
    0x1C,
    0x0C,
    0x1C,
    0x0C,
    0x1C,
    0x1C,
    0x1E,
    0x3C,
    0x0F,
    0xF8,
    0x07,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    /* 9 */
    0x00,
    0x00,
    0x03,
    0xE0,
    0x0F,
    0xF0,
    0x0E,
    0x78,
    0x1C,
    0x18,
    0x18,
    0x1C,
    0x18,
    0x1C,
    0x18,
    0x1C,
    0x1C,
    0x1C,
    0x1E,
    0x3C,
    0x0F,
    0xFC,
    0x07,
    0xFC,
    0x00,
    0x1C,
    0x00,
    0x18,
    0x00,
    0x38,
    0x0C,
    0x70,
    0x0F,
    0xE0,
    0x0F,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

};

const MeowFont meow_font_16 = {
    .data = &fonts1,
    .width = 16,         // 每个字符宽度
    .height = 24,        // 每个字符高度
    .charset = charset1, // 字符集信息
    .charCount = 62      // 字符集大小
};
