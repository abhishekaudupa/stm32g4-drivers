#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>
#include <utils/utils.h>
#include <drivers/rcc/rcc.h>

typedef struct {
    uint32_t GPIO_MODER;
    uint32_t GPIO_OTYPER;
    uint32_t GPIO_OSPEEDR;
    uint32_t GPIO_PUPDR;
    uint32_t GPIO_IDR;
    uint32_t GPIO_ODR;
    uint32_t GPIO_BSRR;
    uint32_t GPIO_LCKR;
    uint32_t GPIO_AFRL;
    uint32_t GPIO_AFRH;
    uint32_t GPIO_BRR;
} GPIO;

/* GPIO modes in MODER */
typedef enum {
    GPIO_MODE_IP = 0x0U,
    GPIO_MODE_OP = 0x1U,
    GPIO_MODE_AF = 0x2U,
    GPIO_MODE_AN = 0x3U,
} GPIO_Mode;

/* GPIO push-pull or open drain in OTYPER */
typedef enum {
    GPIO_OTYPE_PP = 0x0U,
    GPIO_OTYPE_OD = 0x1U,
} GPIO_Output_Type;

/* GPIO pull-up, pull-down or none in PUPDR */
typedef enum {
    GPIO_PP_NO = 0x0U,
    GPIO_PP_PU = 0x1U,
    GPIO_PP_PD = 0x2U,
} GPIO_Push_Pull;

/* GPIO speed in OSPEEDR */
typedef enum {
    GPIO_OSPEED_LS  = 0x0U,
    GPIO_OSPEED_MS  = 0x1U,
    GPIO_OSPEED_HS  = 0x2U,
    GPIO_OSPEED_VHS = 0x3U,
} GPIO_Speed;

/* GPIO alternte funcs in AFRH and AFRL */
typedef enum {
    GPIO_AF00 = 0x0U,
    GPIO_AF01 = 0x1U,
    GPIO_AF02 = 0x2U,
    GPIO_AF03 = 0x3U,
    GPIO_AF04 = 0x4U,
    GPIO_AF05 = 0x5U,
    GPIO_AF06 = 0x6U,
    GPIO_AF07 = 0x7U,
    GPIO_AF08 = 0x8U,
    GPIO_AF09 = 0x9U,
    GPIO_AF10 = 0xAU,
    GPIO_AF11 = 0xBU,
    GPIO_AF12 = 0xCU,
    GPIO_AF13 = 0xDU,
    GPIO_AF14 = 0xEU,
    GPIO_AF15 = 0xFU,
} GPIO_Alternate_Func;

typedef enum {
    GPIO_P00 = 0x0U,
    GPIO_P01 = 0x1U,
    GPIO_P02 = 0x2U,
    GPIO_P03 = 0x3U,
    GPIO_P04 = 0x4U,
    GPIO_P05 = 0x5U,
    GPIO_P06 = 0x6U,
    GPIO_P07 = 0x7U,
    GPIO_P08 = 0x8U,
    GPIO_P09 = 0x9U,
    GPIO_P10 = 0xAU,
    GPIO_P11 = 0xBU,
    GPIO_P12 = 0xCU,
    GPIO_P13 = 0xDU,
    GPIO_P14 = 0xEU,
    GPIO_P15 = 0xFU,
} GPIO_Pin;

/* GPIO registers */
#define GPIOA                           ((volatile GPIO*)0x48000000U)
#define GPIOB                           ((volatile GPIO*)0x48000400U)
#define GPIOC                           ((volatile GPIO*)0x48000800U)
#define GPIOD                           ((volatile GPIO*)0x48000C00U)
#define GPIOE                           ((volatile GPIO*)0x48001000U)
#define GPIOF                           ((volatile GPIO*)0x48001400U)
#define GPIOG                           ((volatile GPIO*)0x48001800U)

/* bit positions for registers */
#define GPIO_MODER_MODE_POS(pin)        ((pin) * 2)
#define GPIO_OSPEEDR_OSPEED_POS(pin)    ((pin) * 2)
#define GPIO_PUPDR_PUPD_POS(pin)        ((pin) * 2)
#define GPIO_AFR_POS(pin)               ((pin) * 4)

/* bitmasks for registers */
#define GPIO_MODER_MODE_BM(pin)         (0x3U << GPIO_MODER_MODE_POS(pin))
#define GPIO_OSPEEDR_OSPEED_BM(pin)     (0x3U << GPIO_OSPEEDR_OSPEED_POS(pin))
#define GPIO_PUPDR_PUPD_BM(pin)         (0x3U << GPIO_PUPDR_PUPD_POS(pin))
#define GPIO_AFR_BM(pin)                (0xFU << GPIO_AFR_POS(pin))
#define GPIO_OTYPER_OTYPE_BM(pin)       (0x1U << (pin))
#define GPIO_IDR_BM(pin)                (0x1U << (pin))
#define GPIO_ODR_BM(pin)                (0x1U << (pin))

/* 
 * GPIO register manipulation functions 
 */

__inline void enable_gpio(const uint8_t port) {
    SET_BIT(RCC->RCC_AHB2ENR, port - 'A');
}

__inline void disable_gpio(const uint8_t port) {
    CLR_BIT(RCC->RCC_AHB2ENR, port - 'A');
}

__inline void set_gpio_mode(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Mode mode) {
    port->GPIO_MODER = (port->GPIO_MODER & ~GPIO_MODER_MODE_BM(pin)) | (mode << GPIO_MODER_MODE_POS(pin));
}

__inline void set_gpio_otype(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Output_Type type) {
    port->GPIO_OTYPER = (port->GPIO_OTYPER & ~GPIO_OTYPER_OTYPE_BM(pin)) | (type << pin);
}

__inline void set_gpio_pupd(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Push_Pull mode) {
    port->GPIO_PUPDR = (port->GPIO_PUPDR & ~GPIO_PUPDR_PUPD_BM(pin)) | (mode << GPIO_PUPDR_PUPD_POS(pin));
}

__inline void set_gpio_speed(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Speed speed) {
    port->GPIO_OSPEEDR = (port->GPIO_OSPEEDR & ~GPIO_OSPEEDR_OSPEED_BM(pin)) | (speed << GPIO_OSPEEDR_OSPEED_POS(pin));
}


__inline void set_gpio_afrl(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Alternate_Func func) {
    port->GPIO_AFRL = (port->GPIO_AFRL & ~GPIO_AFR_BM(pin)) | (func << GPIO_AFR_POS(pin));
}

__inline void set_gpio_afrh(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Alternate_Func func) {
    port->GPIO_AFRH = (port->GPIO_AFRH & ~GPIO_AFR_BM(pin - 8)) | (func << GPIO_AFR_POS(pin - 8));
}

__inline uint32_t gpio_read_odr(volatile GPIO *const port) {
    return port->GPIO_ODR;
}

__inline uint32_t gpio_read_idr(volatile GPIO *const port) {
    return port->GPIO_IDR;
}

__inline void gpio_odr_setpin_atomic(volatile GPIO *const port, const uint8_t pin) {
    SET_BIT(port->GPIO_BSRR, pin);
}

__inline void gpio_odr_resetpin_atomic(volatile GPIO *const port, const uint8_t pin) {
    SET_BIT(port->GPIO_BSRR, pin + 16U);
}

__inline void gpio_set_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    SET_BIT(port->GPIO_ODR, pin);
}

__inline void gpio_clr_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    CLR_BIT(port->GPIO_ODR, pin);
}

__inline void gpio_tgl_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    TGL_BIT(port->GPIO_ODR, pin);
}

__inline void gpio_reset_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    SET_BIT(port->GPIO_BRR, pin);
}

#endif
