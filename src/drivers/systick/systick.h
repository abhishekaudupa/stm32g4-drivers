#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include <stdint.h>
#include <utils/utils.h>

typedef struct {
    uint32_t STK_CTRL;
    uint32_t STK_LOAD;
    uint32_t STK_VAL;
    uint32_t STK_CALIB;
} SysTick;

typedef struct {
    uint32_t load_val:  24;
    uint32_t interrupt: 1;
    uint32_t clk_src:   1;
} Systick_Config;

typedef enum {
    SysTick_Clk_AHB_8 = 0x0U,
    SysTick_Clk_AHB   = 0x1U,
} SysTick_Clksrc;

#define SYSTICK ((volatile SysTick*)0xE000E010)

/* Systick CTRL bit positions */
#define SYSTICK_CTRL_ENABLE     0
#define SYSTICK_CTRL_TICKINT    1
#define SYSTICK_CTRL_CLKSOURCE  2
#define SYSTICK_CTRL_COUNTFLAG  16

/* Systic LOAD and VAL bit position and width */
#define SYSTICK_LOAD            0
#define SYSTICK_WIDTH           24U

void start_systick(const Systick_Config config);
void stop_systick(void);

__inline void enable_systick_interrupt(void) {
    SET_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_TICKINT);
}

__inline void disable_systick_interrupt(void) {
    CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_TICKINT);
}

__inline void enable_systick(void) {
    SET_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_ENABLE);
}

__inline void disable_systick(void) {
    CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_ENABLE);
}

__inline void set_systick_clksrc(const SysTick_Clksrc clk_src) {
    MODIFY_BITS(SYSTICK->STK_CTRL, SYSTICK_CTRL_CLKSOURCE, 1, clk_src);
}

__inline void load_systick(const uint32_t reload_val) {
    MODIFY_BITS(SYSTICK->STK_LOAD, SYSTICK_LOAD, SYSTICK_WIDTH, reload_val);
}

__inline void clear_systick(void) {
    SET_BIT(SYSTICK->STK_VAL, 0);
}

__inline uint8_t read_systick_countflag(void) {
    return TEST_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_COUNTFLAG);
}

#endif
