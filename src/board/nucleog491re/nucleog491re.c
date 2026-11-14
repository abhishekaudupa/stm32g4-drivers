#include <stdint.h>
#include <utils/utils.h>
#include <drivers/gpio/gpio.h>
#include <board/nucleog491re/nucleog491re.h>

void prep_user_led() {
    enable_gpio('A');

    // set GPIOA pin 5 as output
    set_gpio_mode(GPIOA, LD2, GPIO_OP);

    // GPIOA pin 5 is in push-pull mode
    set_gpio_otype(GPIOA, LD2, GPIO_PP);

    // pull-up on GPIOA pin 5
    set_gpio_pupd(GPIOA, LD2, GPIO_PU);
}

void user_led_on(void) {
    gpio_set_pin(GPIOA, LD2);
}

void user_led_off(void) {
    gpio_clr_pin(GPIOA, LD2);
}

void user_leg_tgl(void) {
    gpio_tgl_pin(GPIOA, LD2);
}
