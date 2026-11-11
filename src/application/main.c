#include <stdint.h>
#include <utils/utils.h>
#include <drivers/gpio/gpio.h>
#include <drivers/special/special.h>

#define LD2 5

__inline void prep_user_led() {
    enable_gpio('A');

    // set GPIOA pin 5 as output
    set_gpio_mode(GPIOA, LD2, GPIO_OP);

    // GPIOA pin 5 is in push-pull mode
    set_gpio_otype(GPIOA, LD2, GPIO_PP);

    // pull-up on GPIOA pin 5
    set_gpio_pupd(GPIOA, LD2, GPIO_PU);
}

int main(void) {

    volatile uint32_t reg __unused;

    enable_exceptions();
    disable_irq();
    disable_exceptions();

    return 0;
}
