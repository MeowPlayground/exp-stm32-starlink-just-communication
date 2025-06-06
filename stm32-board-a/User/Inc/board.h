#ifndef __BOARD_H
#define __BOARD_H

#include "stm32f1xx_hal.h"

void sensor_init(void);
void get_sensor_data(float *temperature, float *humidity);
uint8_t get_mp4_concentration(void);

void set_led1(uint8_t state);
void set_led2(uint8_t state);

void set_motor1_speed(uint16_t speed);
void set_motor2_speed(uint16_t speed);
void motor_init(void);
void motor1_stop(void);
void motor2_stop(void);
void motor1_start(void);
void motor2_start(void);
void motor2_reverse(void);

#endif