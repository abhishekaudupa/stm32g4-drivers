#ifndef __RCC_H__
#define __RCC_H__

#include <stdint.h>
#include <utils/utils.h>

typedef struct __packed {
    uint32_t RCC_CR;
    uint32_t RCC_ICSCR;
    uint32_t RCC_CFGR;
    uint32_t RCC_PLLCFGR;
    uint32_t __reserved_1;
    uint32_t __reserved_2;
    uint32_t RCC_CIER;
    uint32_t RCC_CIFR;
    uint32_t RCC_CICR;
    uint32_t __reserved_3;
    uint32_t RCC_AHB1RSTR;
    uint32_t RCC_AHB2RSTR;
    uint32_t RCC_AHB3RSTR;
    uint32_t __reserved_4;
    uint32_t RCC_APB1RSTR1;
    uint32_t RCC_APB1RSTR2;
    uint32_t RCC_APB2RSTR;
    uint32_t __reserved_5;
    uint32_t RCC_AHB1ENR;
    uint32_t RCC_AHB2ENR;
    uint32_t RCC_AHB3ENR;
    uint32_t __reserved_6;
    uint32_t RCC_APB1ENR1;
    uint32_t RCC_APB1ENR2;
    uint32_t RCC_APB2ENR;
    uint32_t __reserved_7;
    uint32_t RCC_AHB1SMENR;
    uint32_t RCC_AHB2SMENR;
    uint32_t RCC_AHB3SMENR;
    uint32_t __reserved_8;
    uint32_t RCC_APB1SMENR1;
    uint32_t RCC_APB1SMENR2;
    uint32_t RCC_APB2SMENR;
    uint32_t __reserved_9;
    uint32_t RCC_CCIPR;
    uint32_t __reserved_10;
    uint32_t RCC_BDCR;
    uint32_t RCC_CSR;
    uint32_t RCC_CRRCR;
    uint32_t RCC_CCIPR2;
} RCC;

#define RCC     ((volatile RCC*) 0X40021000)

#define RCC_CR_HSEON    16
#define RCC_CR_HSERDY   17
#define RCC_CR_HSEBYP   18
#define RCC_CR_HSION    8
#define RCC_CR_HSIRDY   10
#define RCC_CR_PLLON    24
#define RCC_CR_PLLRDY   25

typedef enum {
    RCC_PLL_Src_HSI16   = 0x10U,
    RCC_PLL_Src_HSE     = 0x11U
} RCC_PLL_Src;

typedef enum {
    SysClk_Src_HSI16    = 0x01U,
    SysClk_Src_HSE      = 0x10U,
    SysClk_Src_PLL      = 0x11U
} RCC_SysClk_Src;

__inline void enable_rcc_hse_oscext(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_HSEON);
    while(!TEST_BIT(RCC->RCC_CR, RCC_CR_HSERDY));
}

__inline void disable_rcc_hse_oscext(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_HSEON);
    while(TEST_BIT(RCC->RCC_CR, RCC_CR_HSERDY));
}

__inline void enable_rcc_hse_srcext(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_HSEON);
    SET_BIT(RCC->RCC_CR, RCC_CR_HSEBYP);
}

__inline void disable_rcc_hse_srcext(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_HSEON);
}

__inline void enable_rcc_hsi(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_HSION);
    while(!TEST_BIT(RCC->RCC_CR, RCC_CR_HSIRDY));
}

__inline void disable_rcc_hsi(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_HSION);
    while(TEST_BIT(RCC->RCC_CR, RCC_CR_HSIRDY));
}

__inline void enable_rcc_pll(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_PLLON);
    while(!TEST_BIT(RCC->RCC_CR, RCC_CR_PLLRDY));
}

__inline void disable_rcc_pll(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_PLLON);
    while(TEST_BIT(RCC->RCC_CR, RCC_CR_PLLRDY));
}

__inline void set_rcc_pll_source(const RCC_PLL_Src pll_src) {
    MODIFY_BITS(RCC->RCC_PLLCFGR, 0, 2, pll_src);
}

__inline void set_rcc_sysclk_source(const RCC_PLL_Src sysclk_src) {
    MODIFY_BITS(RCC->RCC_CFGR, 0, 2, sysclk_src);
}

#endif
