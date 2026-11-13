#include <stdint.h>
#include <utils/utils.h>
#include <drivers/gpio/gpio.h>

#define LD2 5

void prep_user_led() {
    enable_gpio('A');

    // set GPIOA pin 5 as output
    set_gpio_mode(GPIOA, LD2, GPIO_OP);

    // GPIOA pin 5 is in push-pull mode
    set_gpio_otype(GPIOA, LD2, GPIO_PP);

    // pull-up on GPIOA pin 5
    set_gpio_pupd(GPIOA, LD2, GPIO_PU);
}
