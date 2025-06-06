#include "meow_oled.h"
#include <string.h>
#include <stdlib.h>
#include "i2c.h"

#define OLED_ADDRESS 0x78 // SSD1306 I2C 地址：0x3C << 1 = 0x78

static I2C_HandleTypeDef *oled_i2c = NULL;
static uint8_t oled_buffer[MEOW_OLED_WIDTH * MEOW_OLED_HEIGHT / 8];

// 写命令
static void oled_write_command(uint8_t cmd)
{
    uint8_t data[2] = {0x00, cmd}; // 0x00: 写命令
    HAL_I2C_Master_Transmit(oled_i2c, OLED_ADDRESS, data, 2, HAL_MAX_DELAY);
}

// 写数据
static void oled_write_data(uint8_t *data, size_t size)
{
    uint8_t *buffer = malloc(size + 1);
    buffer[0] = 0x40; // 0x40: 写数据
    memcpy(&buffer[1], data, size);
    HAL_I2C_Master_Transmit(oled_i2c, OLED_ADDRESS, buffer, size + 1, HAL_MAX_DELAY);
    free(buffer);
}

// 初始化命令序列
static void oled_send_init_sequence(void)
{
    oled_write_command(0xAE); // 关闭显示
    oled_write_command(0x20); // 设置内存地址模式
    oled_write_command(0x00); // 水平地址模式
    oled_write_command(0xB0); // 页地址
    oled_write_command(0xC8); // COM扫描方向
    oled_write_command(0x00); // 设置低列地址
    oled_write_command(0x10); // 设置高列地址
    oled_write_command(0x40); // 设置起始行
    oled_write_command(0x81); // 对比度
    oled_write_command(0x7F);
    oled_write_command(0xA1); // 段重定向
    oled_write_command(0xA6); // 正常显示
    oled_write_command(0xA8); // 多路复用比
    oled_write_command(0x3F);
    oled_write_command(0xA4); // 显示全部点关闭
    oled_write_command(0xD3); // 显示偏移
    oled_write_command(0x00);
    oled_write_command(0xD5); // 显示时钟分频比/振荡器频率
    oled_write_command(0x80);
    oled_write_command(0xD9); // 预充电周期
    oled_write_command(0xF1);
    oled_write_command(0xDA); // COM引脚硬件配置
    oled_write_command(0x12);
    oled_write_command(0xDB); // VCOMH 取消选择级别
    oled_write_command(0x40);
    oled_write_command(0x8D); // 电荷泵设置
    oled_write_command(0x14);
    oled_write_command(0xAF); // 打开显示
}

// 初始化
void Meow_OLED_Init(I2C_HandleTypeDef *hi2c)
{
    oled_i2c = hi2c;
    HAL_Delay(100);
    memset(oled_buffer, 0x00, sizeof(oled_buffer));
    oled_send_init_sequence();
    Meow_OLED_Refresh();
}

// 清屏
void Meow_OLED_ClearScreen(void)
{
    memset(oled_buffer, 0x00, sizeof(oled_buffer));
}

// 设置一个像素
void Meow_OLED_DrawPixel(uint8_t x, uint8_t y, bool on)
{
    if (x >= MEOW_OLED_WIDTH || y >= MEOW_OLED_HEIGHT)
        return;
    uint16_t index = x + (y / 8) * MEOW_OLED_WIDTH;
    if (on)
        oled_buffer[index] |= (1 << (y % 8));
    else
        oled_buffer[index] &= ~(1 << (y % 8));
}

// 刷新整个屏幕（写整个缓冲区）
void Meow_OLED_Refresh(void)
{
    for (uint8_t page = 0; page < (MEOW_OLED_HEIGHT / 8); page++)
    {
        oled_write_command(0xB0 + page); // 设置页地址
        oled_write_command(0x00);        // 设置列地址低位
        oled_write_command(0x10);        // 设置列地址高位
        oled_write_data(&oled_buffer[MEOW_OLED_WIDTH * page], MEOW_OLED_WIDTH);
    }
}
