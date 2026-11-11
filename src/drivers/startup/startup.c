#include <stdint.h>
#include "startup.h"

// after reset, main function for user.
extern int main(void);

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void default_handler(void) {
    while(1);
}

void reset_handler(void) {
    int ret __unused;

    uint32_t data_size = (uint8_t*)&_edata - (uint8_t*)&_sdata;
    uint32_t bss_size = (uint8_t*)&_ebss - (uint8_t*)&_sbss;

    // copy data to SRAM
    uint8_t *p_src = (uint8_t*)&_etext;
    uint8_t *p_dst = (uint8_t*)&_sdata;
    for (uint32_t i = 0; i < data_size; ++i) {
        p_dst[i] = p_src[i];
    }

    // zero out BSS in SRAM.
    p_dst = (uint8_t*)&_sbss;
    for (uint32_t i = 0; i < bss_size; ++i)
        p_dst[i] = 0;

    ret = main();

    // don't fall through.
    while(1);
}
