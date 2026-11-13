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
    GPIO_IP = 0x0U,
    GPIO_OP = 0x1U,
    GPIO_AF = 0x2U,
    GPIO_AN = 0x3U,
} GPIO_Mode;

/* GPIO push-pull or open drain in OTYPER */
typedef enum {
    GPIO_PP = 0x0U,
    GPIO_OD = 0x1U,
} GPIO_Output_Type;

/* GPIO pull-up, pull-down or none in PUPDR */
typedef enum {
    GPIO_NO = 0x0U,
    GPIO_PU = 0x1U,
    GPIO_PD = 0x2U,
} GPIO_Push_Pull;

/* GPIO speed in OSPEEDR */
typedef enum {
    GPIO_LS = 0x0U,
    GPIO_MS = 0x1U,
    GPIO_HS = 0x2U,
    GPIO_VHS = 0x3U,
} GPIO_Speed;

/* GPIO alternte funcs in AFRH and AFRL */
typedef enum {
    GPIO_AF00 = 0x0,
    GPIO_AF01 = 0x1,
    GPIO_AF02 = 0x2,
    GPIO_AF03 = 0x3,
    GPIO_AF04 = 0x4,
    GPIO_AF05 = 0x5,
    GPIO_AF06 = 0x6,
    GPIO_AF07 = 0x7,
    GPIO_AF08 = 0x8,
    GPIO_AF09 = 0x9,
    GPIO_AF10 = 0xA,
    GPIO_AF11 = 0xB,
    GPIO_AF12 = 0xC,
    GPIO_AF13 = 0xD,
    GPIO_AF14 = 0xE,
    GPIO_AF15 = 0xF,
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

#define GPIOA                   ((volatile GPIO*)0x48000000)
#define GPIOB                   ((volatile GPIO*)0x48000400)
#define GPIOC                   ((volatile GPIO*)0x48000800)
#define GPIOD                   ((volatile GPIO*)0x48000C00)
#define GPIOE                   ((volatile GPIO*)0x48001000)
#define GPIOF                   ((volatile GPIO*)0x48001400)
#define GPIOG                   ((volatile GPIO*)0x48001800)

#define GPIO_MODER_IWIDTH       0x2U
#define GPIO_OTYPER_IWIDTH      0x1U
#define GPIO_OSPEEDR_IWIDTH     0x2U
#define GPIO_PUPDR_IWIDTH       0x2U
#define GPIO_AFR_IWIDTH         0x4U

#define GPIO_MODER_IOFST(pin)   ((pin) * GPIO_MODER_IWIDTH)        
#define GPIO_OTYPER_IOFST(pin)  ((pin) * GPIO_OTYPER_IWIDTH)
#define GPIO_OSPEEDR_IOFST(pin) ((pin) * GPIO_OSPEEDR_IWIDTH)
#define GPIO_PUPDR_IOFST(pin)   ((pin) * GPIO_PUPDR_IWIDTH)
#define GPIO_AFR_IOFST(pin)     ((pin) * GPIO_AFR_IWIDTH)

__inline void enable_gpio(const uint8_t port) {
    SET_BIT(RCC->RCC_AHB2ENR, port - 'A');
}

__inline void disable_gpio(const uint8_t port) {
    CLR_BIT(RCC->RCC_AHB2ENR, port - 'A');
}

__inline void set_gpio_mode(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Mode mode) {
    MODIFY_BITS(port->GPIO_MODER, GPIO_MODER_IOFST(pin), GPIO_MODER_IWIDTH, mode);
}

__inline void set_gpio_otype(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Output_Type type) {
    MODIFY_BITS(port->GPIO_OTYPER, GPIO_OTYPER_IOFST(pin), GPIO_OTYPER_IWIDTH, type);
}

__inline void set_gpio_pupd(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Push_Pull mode) {
    MODIFY_BITS(port->GPIO_PUPDR, GPIO_PUPDR_IOFST(pin), GPIO_PUPDR_IWIDTH, mode);
}

__inline void set_gpio_speed(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Speed speed) {
    MODIFY_BITS(port->GPIO_OSPEEDR, GPIO_OSPEEDR_IOFST(pin), GPIO_OSPEEDR_IWIDTH, speed);
}


__inline void set_gpio_afrl(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Alternate_Func func) {
    MODIFY_BITS(port->GPIO_AFRL, GPIO_AFR_IOFST(pin), GPIO_AFR_IWIDTH, func);
}

__inline void set_gpio_afrh(volatile GPIO *const port, 
        const uint8_t pin, 
        const GPIO_Alternate_Func func) {
    MODIFY_BITS(port->GPIO_AFRH, GPIO_AFR_IOFST(pin - 8), GPIO_AFR_IWIDTH, func);
}

__inline uint32_t gpio_read_odr(volatile GPIO *const port) {
    return port->GPIO_ODR;
}

__inline uint32_t gpio_read_idr(volatile GPIO *const port) {
    return port->GPIO_IDR;
}

__inline void gpio_odr_setbit_atomic(volatile GPIO *const port, const uint8_t bit) {
    SET_BIT(port->GPIO_BSRR, bit);
}

__inline void gpio_odr_resetbit_atomic(volatile GPIO *const port, const uint8_t bit) {
    SET_BIT(port->GPIO_BSRR, bit + 16U);
}

__inline void gpio_set_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    SET_BIT(port->GPIO_ODR, pin);
}

__inline void gpio_clr_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    CLR_BIT(port->GPIO_ODR, pin);
}

__inline void gpio_reset_pin(volatile GPIO *const port, const GPIO_Pin pin) {
    SET_BIT(port->GPIO_BRR, pin);
}

#endif
