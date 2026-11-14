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

#define SYSTICK                     ((volatile SysTick*)0xE000E010U)

/* Systick register bit positions */
#define SYSTICK_CTRL_ENABLE_POS     0
#define SYSTICK_CTRL_TICKINT_POS    1
#define SYSTICK_CTRL_CLKSRC_POS     2
#define SYSTICK_CTRL_COUNTFLAG_POS  16
#define SYSTICK_LOAD_POS            0
#define SYSTICK_VAL_POS             0

/* Systick register bitmasks */
#define SYSTICK_CTRL_ENABLE_BM      (0X1U << SYSTICK_CTRL_ENABLE_POS)
#define SYSTICK_CTRL_TICKINT_BM     (0X1U << SYSTICK_CTRL_TICKINT_POS)
#define SYSTICK_CTRL_CLKSRC_BM      (0X1U << SYSTICK_CTRL_CLKSRC_POS)
#define SYSTICK_CTRL_COUNTFLAG_BM   (0X1U << SYSTICK_CTRL_COUNTFLAG_POS)
#define SYSTICK_LOAD_BM             (0XFFFFFF << SYSTICK_LOAD_POS)
#define SYSTICK_VAL_BM              (0xFFFFFF << SYSTICK_VAL_POS)

void start_systick(const Systick_Config config);
void stop_systick(void);

__inline void enable_systick_interrupt(void) {
    SET_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_TICKINT_POS);
}

__inline void disable_systick_interrupt(void) {
    CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_TICKINT_POS);
}

__inline void enable_systick(void) {
    SET_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_ENABLE_POS);
}

__inline void disable_systick(void) {
    CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_ENABLE_POS);
}

__inline void set_systick_clksrc(const SysTick_Clksrc clk_src) {
    SYSTICK->STK_CTRL = (SYSTICK->STK_CTRL & ~SYSTICK_CTRL_CLKSRC_BM) | (clk_src << SYSTICK_CTRL_CLKSRC_POS); 
}

__inline void load_systick(const uint32_t reload_val) {
    SYSTICK->STK_LOAD = reload_val & SYSTICK_LOAD_BM;
}

__inline void clear_systick(void) {
    SET_BIT(SYSTICK->STK_VAL, 0);
}

__inline uint8_t read_systick_countflag(void) {
    return TST_BIT(SYSTICK->STK_CTRL, SYSTICK_CTRL_COUNTFLAG_POS);
}

#endif
