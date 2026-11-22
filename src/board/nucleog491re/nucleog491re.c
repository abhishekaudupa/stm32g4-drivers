#include <stdint.h>
#include <utils/utils.h>
#include <drivers/gpio/gpio.h>
#include <board/nucleog491re/nucleog491re.h>

void prep_user_led() {
    enable_gpio('A');

    // set GPIOA pin 5 as output
    set_gpio_mode(GPIOA, LD2, GPIO_MODE_OP);

    // GPIOA pin 5 is in push-pull mode
    set_gpio_otype(GPIOA, LD2, GPIO_OTYPE_PP);

    // pull-up on GPIOA pin 5
    set_gpio_pupd(GPIOA, LD2, GPIO_PP_PU);
}

void user_led_on(void) {
    gpio_set_pin(GPIOA, LD2);
}

void user_led_off(void) {
    gpio_clr_pin(GPIOA, LD2);
}

void user_led_tgl(void) {
    gpio_tgl_pin(GPIOA, LD2);
}

void enable_lpuart_pins(void) {
    enable_gpio('A');
    set_gpio_mode(GPIOA, LPUART1_TX, GPIO_MODE_AF);
    set_gpio_otype(GPIOA, LPUART1_TX, GPIO_OTYPE_PP);
    set_gpio_pupd(GPIOA, LPUART1_TX, GPIO_PP_NO);
    set_gpio_afrl(GPIOA, LPUART1_TX, GPIO_AF12);
    set_gpio_mode(GPIOA, LPUART1_RX, GPIO_MODE_AF);
    set_gpio_otype(GPIOA, LPUART1_RX, GPIO_OTYPE_PP);
    set_gpio_pupd(GPIOA, LPUART1_RX, GPIO_PP_NO);
    set_gpio_afrl(GPIOA, LPUART1_RX, GPIO_AF12);
}
