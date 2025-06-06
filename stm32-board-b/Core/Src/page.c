// pages.c
#include "page.h"
#include "meow_oled.h"
#include "i2c.h"
#include "stm32f1xx_hal.h"

#define FLASH_USER_START_ADDR ((uint32_t)0x0800FC00) // 最后一页起始地址（1KB 页大小）

Page pages[PAGE_COUNT];
int current_page = PAGE_HOME;

void init_pages(void)
{
    pages[PAGE_HOME] = (Page){page_home_setup, page_home_loop, NULL};
    pages[PAGE_STATUS] = (Page){page_status_setup, page_status_loop, handle_status_event};
    pages[PAGE_SETTINGS] = (Page){page_settings_setup, page_settings_loop, handle_settings_event};
    pages[PAGE_ALARM] = (Page){page_alarm_setup, page_alarm_loop, handle_alarm_event};

    pages[current_page].setup(); // 初始化当前页
}

void switch_to_page(int page_index)
{
    if (page_index < 0 || page_index >= PAGE_COUNT)
        return;
    current_page = page_index;
    pages[current_page].setup();
}

void run_current_page_loop(void)
{
    pages[current_page].loop();
}

void Save_Thresholds_To_Flash(void)
{
    HAL_FLASH_Unlock();

    // 擦除 Flash 最后一页
    FLASH_EraseInitTypeDef erase_init;
    uint32_t page_error = 0;
    erase_init.TypeErase = FLASH_TYPEERASE_PAGES;
    erase_init.PageAddress = FLASH_USER_START_ADDR;
    erase_init.NbPages = 1;

    if (HAL_FLASHEx_Erase(&erase_init, &page_error) != HAL_OK)
    {
        HAL_FLASH_Lock();
        return; // 擦除失败
    }

    // 按半字写入（必须为16位对齐）
    uint32_t addr = FLASH_USER_START_ADDR;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, (uint16_t)temp_high_threshold);
    addr += 2;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, (uint16_t)temp_low_threshold);
    addr += 2;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, (uint16_t)humidity_high_threshold);
    addr += 2;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, (uint16_t)humidity_low_threshold);
    addr += 2;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, (uint16_t)(light_threshold >> 8));
    addr += 2;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, (uint16_t)(light_threshold & 0xFF));
    addr += 2;

    HAL_FLASH_Lock();
}

void Load_Thresholds_From_Flash(void)
{
    uint32_t addr = FLASH_USER_START_ADDR;

    temp_high_threshold = *(int16_t *)(addr);
    addr += 2;
    temp_low_threshold = *(int16_t *)(addr);
    addr += 2;
    humidity_high_threshold = *(int16_t *)(addr);
    addr += 2;
    humidity_low_threshold = *(int16_t *)(addr);
    addr += 2;

    uint8_t light_high = *(uint16_t *)(addr);
    addr += 2;
    uint8_t light_low = *(uint16_t *)(addr);
    addr += 2;
    light_threshold = ((uint16_t)light_high << 8) | light_low;
}
