#ifndef __RCC_H__
#define __RCC_H__

#include <stdint.h>
#include <utils/utils.h>

typedef struct {
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

/* RCC peripheral location */
#define RCC                         ((volatile RCC*) 0X40021000U)

/* bit positions in registers */
#define RCC_CR_HSION_POS            8
#define RCC_CR_HSIKERON_POS         9
#define RCC_CR_HSIRDY_POS           10
#define RCC_CR_HSEON_POS            16
#define RCC_CR_HSERDY_POS           17
#define RCC_CR_HSEBYP_POS           18
#define RCC_CR_PLLON_POS            24
#define RCC_CR_PLLRDY_POS           25
#define RCC_CFGR_SW_POS             0
#define RCC_CFGR_SWS_POS            2
#define RCC_PLLCFGR_PLLSRC_POS      0

/* bitmasks for registers */
#define RCC_CR_HSION_BM            (0x1U << RCC_CR_HSION_POS)
#define RCC_CR_HSIRDY_BM           (0x1U << RCC_CR_HSIRDY_POS)
#define RCC_CR_HSEON_BM            (0x1U << RCC_CR_HSEON_POS)
#define RCC_CR_HSERDY_BM           (0x1U << RCC_CR_HSERDY_POS)
#define RCC_CR_HSEBYP_BM           (0x1U << RCC_CR_HSEBYP_POS)
#define RCC_CR_PLLON_BM            (0x1U << RCC_CR_PLLON_POS)
#define RCC_CR_PLLRDY_BM           (0x1U << RCC_CR_PLLRDY_POS)
#define RCC_CFGR_SW_BM             (0x3U << RCC_CFGR_SW_POS)
#define RCC_CFGR_SWS_BM            (0x3U << RCC_CFGR_SWS_POS)
#define RCC_PLLCFGR_PLLSRC_BM      (0x3U << RCC_PLLCFGR_PLLSRC_POS)

typedef enum {
    RCC_PLL_Src_None    = 0x0U,
    RCC_PLL_Src_HSI16   = 0x2U,
    RCC_PLL_Src_HSE     = 0x3U
} RCC_PLL_Src;

typedef enum {
    SysClk_Src_HSI16    = 0x1U,
    SysClk_Src_HSE      = 0x2U,
    SysClk_Src_PLL      = 0x3U
} RCC_SysClk_Src;

__inline void enable_rcc_hse_oscext(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_HSEON_POS);
    while(!TST_BIT(RCC->RCC_CR, RCC_CR_HSERDY_POS));
}

__inline void disable_rcc_hse_oscext(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_HSEON_POS);
    while(TST_BIT(RCC->RCC_CR, RCC_CR_HSERDY_POS));
}

__inline void enable_rcc_hse_srcext(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_HSEON_POS);
    SET_BIT(RCC->RCC_CR, RCC_CR_HSEBYP_POS);
}

__inline void disable_rcc_hse_srcext(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_HSEON_POS);
}

__inline void enable_rcc_hsi(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_HSION_POS);
    while(!TST_BIT(RCC->RCC_CR, RCC_CR_HSIRDY_POS));
}

__inline void disable_rcc_hsi(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_HSION_POS);
    while(TST_BIT(RCC->RCC_CR, RCC_CR_HSIRDY_POS));
}

__inline void enable_rcc_pll(void) {
    SET_BIT(RCC->RCC_CR, RCC_CR_PLLON_POS);
    while(!TST_BIT(RCC->RCC_CR, RCC_CR_PLLRDY_POS));
}

__inline void disable_rcc_pll(void) {
    CLR_BIT(RCC->RCC_CR, RCC_CR_PLLON_POS);
    while(TST_BIT(RCC->RCC_CR, RCC_CR_PLLRDY_POS));
}

__inline void set_rcc_pll_source(const RCC_PLL_Src pll_src) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLSRC_BM) | (pll_src << RCC_PLLCFGR_PLLSRC_POS); 
}

__inline void set_rcc_sysclk_source(const RCC_SysClk_Src sysclk_src) {
    RCC->RCC_CFGR = ((RCC->RCC_CFGR & ~RCC_CFGR_SW_BM) | (sysclk_src << RCC_CFGR_SW_POS));
}

#endif
