#include <stdint.h>
#include <utils/utils.h>
#include <drivers/gpio/gpio.h>
#include <drivers/nvic/nvic.h>
#include <drivers/systick/systick.h>
#include <drivers/asm/asm.h>
#include <board/nucleog491re/nucleog491re.h>

void sysTick_handler() {
    TOG_BIT(GPIOA->GPIO_ODR, LD2);
}

int main(void) {
    prep_user_led();
    load_systick(1600000U);
    clear_systick();
    set_systick_clksrc_ahb();
    enable_systick_interrupt();
    enable_systick();
    return 0;
}
