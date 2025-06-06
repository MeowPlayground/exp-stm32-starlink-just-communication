// page.h
#ifndef PAGE_H
#define PAGE_H
#include <stdint.h>
#include "ds1307.h"

typedef void (*PageFunc)(void);
typedef void (*ButtonHandler)(uint16_t gpio);

typedef struct
{
    PageFunc setup;
    PageFunc loop;
    ButtonHandler button_event_handler;
} Page;

extern void switch_to_page(int page_index);
extern void run_current_page_loop(void);
extern void init_pages(void);

// 页面的索引
#define PAGE_HOME 0
#define PAGE_STATUS 1
#define PAGE_SETTINGS 2
#define PAGE_ALARM 3
#define PAGE_COUNT 4

// 按钮引脚定义
#define ADD_BITTON GPIO_PIN_3
#define SUB_BITTON GPIO_PIN_4
#define CONFIRM_BITTON GPIO_PIN_6
#define CANCEL_BITTON GPIO_PIN_7

// 页面函数声明
extern void page_home_setup(void);
extern void page_home_loop(void);
extern void page_settings_setup(void);
extern void page_settings_loop(void);
extern void page_alarm_setup(void);
extern void page_alarm_loop(void);
extern void page_status_setup(void);
extern void page_status_loop(void);

extern void handle_status_event(uint16_t gpio);
extern void handle_settings_event(uint16_t gpio);
extern void handle_alarm_event(uint16_t gpio);

// eeprom
void Save_Thresholds_To_Flash(void);
void Load_Thresholds_From_Flash(void);

// 页面变量
extern uint8_t led1_status;  // LED1状态
extern uint8_t led2_status;  // LED2状态
extern uint8_t fan_status;   // 风扇状态
extern uint8_t motor_status; // 电机状态
extern uint8_t radio_status; // 雷达状态
extern uint8_t auto_mode;    // 自动模式开关，0: 关闭, 1: 开启

// 阈值
extern int8_t temp_high_threshold;     // 温度高阈值
extern int8_t temp_low_threshold;      // 温度低阈值
extern int8_t humidity_high_threshold; // 湿度高阈值
extern int8_t humidity_low_threshold;  // 湿度低阈值
extern uint16_t light_threshold;       // 光照阈值

// 报警
extern uint8_t alert_type;
extern uint32_t alert_cooldown; // 警报冷却时间

extern DS1307_Time current_time; // 当前时间

static int8_t current_point = 0; // 用于指示当前选中的设置项

extern Page pages[PAGE_COUNT];
extern int current_page;

#endif // PAGE_H
