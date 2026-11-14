#include <drivers/systick/systick.h>

void start_systick(const Systick_Config config) {
    load_systick(config.load_val);
    clear_systick();
    set_systick_clksrc(config.clk_src);
    if (config.interrupt)
        enable_systick_interrupt();
    else
        disable_systick_interrupt();
    enable_systick();
}

void stop_systick(void) {
    disable_systick_interrupt();
    disable_systick();
}
