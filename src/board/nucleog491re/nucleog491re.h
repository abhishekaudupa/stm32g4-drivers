#ifndef __NUCLEOG491RE_H__
#define __NUCLEOG491RE_H__

#include <drivers/gpio/gpio.h>

#define LD2         GPIO_P05
#define LPUART1_TX  GPIO_P02
#define LPUART1_RX  GPIO_P03

void prep_user_led();

void user_led_on(void);

void user_led_off(void);

void user_led_tgl(void);

void enable_lpuart_pins(void);

#endif
