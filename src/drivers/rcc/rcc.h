#ifndef __RCC_H__
#define __RCC_H__

#include <stdint.h>
#include <utils/utils.h>
#include <drivers/rcc/pll_hsi16_match.h>
#include <drivers/rcc/pll_hse24_match.h>

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
#define RCC_CFGR_HPRE_POS           4
#define RCC_CFGR_PPRE1_POS          8
#define RCC_CFGR_PPRE2_POS          11
#define RCC_PLLCFGR_PLLSRC_POS      0
#define RCC_PLLCFGR_PLLM_POS        4
#define RCC_PLLCFGR_PLLN_POS        8
#define RCC_PLLCFGR_PLLPEN_POS      16
#define RCC_PLLCFGR_PLLP_POS        17
#define RCC_PLLCFGR_PLLQEN_POS      20
#define RCC_PLLCFGR_PLLQ_POS        21
#define RCC_PLLCFGR_PLLREN_POS      24
#define RCC_PLLCFGR_PLLR_POS        25
#define RCC_PLLCFGR_PLLPDIV_POS     27

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
#define RCC_CFGR_HPRE_BM           (0xFU << RCC_CFGR_HPRE_POS)
#define RCC_CFGR_PPRE1_BM          (0x7U << RCC_CFGR_PPRE1_POS)
#define RCC_CFGR_PPRE2_BM          (0x7U << RCC_CFGR_PPRE2_POS)
#define RCC_PLLCFGR_PLLSRC_BM      (0x3U << RCC_PLLCFGR_PLLSRC_POS)
#define RCC_PLLCFGR_PLLM_BM        (0xFU << RCC_PLLCFGR_PLLM_POS)
#define RCC_PLLCFGR_PLLN_BM        (0x7FU << RCC_PLLCFGR_PLLN_POS)
#define RCC_PLLCFGR_PLLPEN_BM      (0x1U << RCC_PLLCFGR_PLLPEN_POS)
#define RCC_PLLCFGR_PLLP_BM        (0x1U << RCC_PLLCFGR_PLLP_POS)
#define RCC_PLLCFGR_PLLQEN_BM      (0x1U << RCC_PLLCFGR_PLLQEN_POS)
#define RCC_PLLCFGR_PLLQ_BM        (0x3U << RCC_PLLCFGR_PLLQ_POS)
#define RCC_PLLCFGR_PLLREN_BM      (0x1U << RCC_PLLCFGR_PLLREN_POS)
#define RCC_PLLCFGR_PLLR_BM        (0x3U << RCC_PLLCFGR_PLLR_POS)
#define RCC_PLLCFGR_PLLPDIV_BM     (0x1FU << RCC_PLLCFGR_PLLPDIV_POS)

/* PLL clock division/multiplication macros */
#define RCC_PLLCFGR_PLLPDIV(n)     (n)
#define RCC_PLLCFGR_PLLQ(n)        (n / 2 - 1)
#define RCC_PLLCFGR_PLLR(n)        (n / 2 - 1)
#define RCC_PLLCFGR_PLLN(n)        (n)
#define RCC_PLLCFGR_PLLM(n)        (n - 1)

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

typedef enum {
    AHB_Presc_1   = 0x0U,
    AHB_Presc_2   = 0x8U,
    AHB_Presc_4   = 0x8U,
    AHB_Presc_8   = 0xAU,
    AHB_Presc_16  = 0xBU,
    AHB_Presc_64  = 0xCU,
    AHB_Presc_128 = 0xDU,
    AHB_Presc_256 = 0xEU,
    AHB_Presc_516 = 0xFU,
} RCC_AHB_Prescaler;

typedef enum {
    APB_Presc_1  = 0x0U,
    APB_Presc_2  = 0x4U,
    APB_Presc_4  = 0x5U,
    APB_Presc_8  = 0x6U,
    APB_Presc_16 = 0x7U,
} RCC_APB_Prescaler;

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

__inline void set_rcc_sysclk_source(const RCC_SysClk_Src sysclk_src) {
    RCC->RCC_CFGR = (RCC->RCC_CFGR & ~RCC_CFGR_SW_BM) | (sysclk_src << RCC_CFGR_SW_POS);
}

__inline void rcc_prescale_ahb(const RCC_AHB_Prescaler presc) {
    RCC->RCC_CFGR = (RCC->RCC_CFGR & ~RCC_CFGR_HPRE_BM) | (presc << RCC_CFGR_HPRE_POS);
}

__inline void rcc_prescale_apb1(const RCC_APB_Prescaler presc) {
    RCC->RCC_CFGR = (RCC->RCC_CFGR & ~RCC_CFGR_PPRE1_BM) | (presc << RCC_CFGR_PPRE1_POS);
}

__inline void rcc_prescale_apb2(const RCC_APB_Prescaler presc) {
    RCC->RCC_CFGR = (RCC->RCC_CFGR & ~RCC_CFGR_PPRE2_BM) | (presc << RCC_CFGR_PPRE2_POS);
}

__inline void set_rcc_pll_source(const RCC_PLL_Src pll_src) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLSRC_BM) | (pll_src << RCC_PLLCFGR_PLLSRC_POS); 
}

__inline void set_rcc_pllm_div(const uint8_t div_m) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLM_BM) | (div_m << RCC_PLLCFGR_PLLM_POS);
}

__inline void set_rcc_plln_mul(const uint8_t mul_n) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLN_BM) | (mul_n << RCC_PLLCFGR_PLLN_POS);
}

__inline void set_rcc_pllp_div_7(void) {
    CLR_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLP_POS);
}

__inline void set_rcc_pllp_div_17(void) {
    SET_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLP_POS);
}

__inline void set_rcc_pllp_div(const uint8_t div_p) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLPDIV_BM) | (div_p << RCC_PLLCFGR_PLLPDIV_POS);
}

__inline void set_rcc_pllq_div(const uint8_t div_q) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLQ_BM) | (div_q << RCC_PLLCFGR_PLLQ_POS);
}

__inline void set_rcc_pllr_div(const uint8_t div_r) {
    RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & ~RCC_PLLCFGR_PLLR_BM) | (div_r << RCC_PLLCFGR_PLLR_POS);
}

__inline void enable_rcc_pllp(void) {
    SET_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLPEN_POS);
}

__inline void disable_rcc_pllp(void) {
    CLR_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLPEN_POS);
}

__inline void enable_rcc_pllq(void) {
    SET_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLQEN_POS);
}

__inline void disable_rcc_pllq(void) {
    CLR_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLQEN_POS);
}

__inline void enable_rcc_pllr(void) {
    SET_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLREN_POS);
}
__inline void disable_rcc_pllr(void) {
    CLR_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_PLLREN_POS);
}

#endif
