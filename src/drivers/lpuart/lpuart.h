#ifndef __LPUART_H__
#define __LPUART_H__

#include <stdint.h>
#include <utils/utils.h>
#include <drivers/rcc/rcc.h>

typedef struct {
    uint32_t LPUART_CR1;
    uint32_t LPUART_CR2;
    uint32_t LPUART_CR3;
    uint32_t LPUART_BRR;
    uint32_t __reserved_1;
    uint32_t __reserved_2;
    uint32_t LPUART_RQR;
    uint32_t LPUART_ISR;
    uint32_t LPUART_ICR;
    uint32_t LPUART_RDR;
    uint32_t LPUART_TDR;
    uint32_t LPUART_PRESC;
} LPUART;

#define LPUART      ((volatile LPUART*) 0x40008000U)

/* bit positions for registers */
#define LPUART_CR1_RXFFIE_POS               31
#define LPUART_CR1_TXFEIE_POS               30
#define LPUART_CR1_FIFOEN_POS               29
#define LPUART_CR1_M1_POS                   28
#define LPUART_CR1_M0_POS                   12
#define LPUART_CR1_TXFNFIE_POS              7
#define LPUART_CR1_TCIE_POS                 6
#define LPUART_CR1_RXFNEIE_POS              5
#define LPUART_CR1_IDLEIE_POS               4
#define LPUART_CR1_TE_POS                   3
#define LPUART_CR1_RE_POS                   2
#define LPUART_CR1_UE_POS                   0
#define LPUART_CR2_STOP_POS                 12
#define LPUART_CR3_TXFTCFG_POS              29
#define LPUART_CR3_RXFTIE_POS               28
#define LPUART_CR3_RXFTCFG_POS              25
#define LPUART_CR3_TXFTIE_POS               23
#define LPUART_CR3_HDSEL_POS                3
#define LPUART_CR3_EIE_POS                  0
#define LPUART_BRR_BRR_POS                  0
#define LPUART_ISR_TXFT_POS                 27
#define LPUART_ISR_RXFT_POS                 26
#define LPUART_ISR_RXFF_POS                 24
#define LPUART_ISR_TXFE_POS                 23
#define LPUART_ISR_REACK_POS                22
#define LPUART_ISR_TEACK_POS                21
#define LPUART_ISR_BUSY_POS                 16
#define LPUART_ISR_TXFNF_POS                7
#define LPUART_ISR_TC_POS                   6
#define LPUART_ISR_RXFNE_POS                5
#define LPUART_ISR_IDLE_POS                 4
#define LPUART_ISR_ORE_POS                  3
#define LPUART_ISR_NE_POS                   2
#define LPUART_ISR_FE_POS                   1
#define LPUART_ICR_TCCF_POS                 6
#define LPUART_ICR_IDLECF_POS               4
#define LPUART_ICR_ORECF_POS                3
#define LPUART_ICR_NECF_POS                 2
#define LPUART_ICR_FECF_POS                 1
#define LPUART_PRESC_PRESC_POS              0

/* bit masks for registers */
#define LPUART_CR1_RXFFIE_BM               (0x1U << LPUART_CR1_RXFFIE_POS)
#define LPUART_CR1_TXFEIE_BM               (0x1U << LPUART_CR1_TXFEIE_POS)
#define LPUART_CR1_FIFOEN_BM               (0x1U << LPUART_CR1_FIFOEN_POS)
#define LPUART_CR1_M1_BM                   (0x1U << LPUART_CR1_M1_POS)
#define LPUART_CR1_M0_BM                   (0x1U << LPUART_CR1_M0_POS)
#define LPUART_CR1_TXFNFIE_BM              (0x1U << LPUART_CR1_TXFNFIE_POS)
#define LPUART_CR1_TCIE_BM                 (0x1U << LPUART_CR1_TCIE_POS)
#define LPUART_CR1_RXFNEIE_BM              (0x1U << LPUART_CR1_RXFNEIE_POS)
#define LPUART_CR1_IDLEIE_BM               (0x1U << LPUART_CR1_IDLEIE_POS)
#define LPUART_CR1_TE_BM                   (0x1U << LPUART_CR1_TE_POS)
#define LPUART_CR1_RE_BM                   (0x1U << LPUART_CR1_RE_POS)
#define LPUART_CR1_UE_BM                   (0x1U << LPUART_CR1_UE_POS)
#define LPUART_CR2_STOP_BM                 (0x3 << LPUART_CR2_STOP_POS) 
#define LPUART_CR3_TXFTCFG_BM              (0x7U << LPUART_CR3_TXFTCFG_POS)
#define LPUART_CR3_RXFTIE_BM               (0x1U << LPUART_CR3_RXFTIE_POS)
#define LPUART_CR3_RXFTCFG_BM              (0x7U << LPUART_CR3_RXFTCFG_POS)
#define LPUART_CR3_TXFTIE_BM               (0x1U << LPUART_CR3_TXFTIE_POS)
#define LPUART_CR3_HDSEL_BM                (0x1U << LPUART_CR3_HDSEL_POS)
#define LPUART_CR3_EIE_BM                  (0x1U << LPUART_CR3_EIE_POS)
#define LPUART_BRR_BRR_BM                  (0xFFFFF << LPUART_BRR_BRR_POS)
#define LPUART_ISR_TXFT_BM                 (0x1U << LPUART_ISR_TXFT_POS)
#define LPUART_ISR_RXFT_BM                 (0x1U << LPUART_ISR_RXFT_POS)
#define LPUART_ISR_RXFF_BM                 (0x1U << LPUART_ISR_RXFF_POS)
#define LPUART_ISR_TXFE_BM                 (0x1U << LPUART_ISR_TXFE_POS)
#define LPUART_ISR_REACK_BM                (0x1U << LPUART_ISR_REACK_POS)
#define LPUART_ISR_TEACK_BM                (0x1U << LPUART_ISR_TEACK_POS)
#define LPUART_ISR_BUSY_BM                 (0x1U << LPUART_ISR_BUSY_POS)
#define LPUART_ISR_TXFNF_BM                (0x1U << LPUART_ISR_TXFNF_POS)
#define LPUART_ISR_TC_BM                   (0x1U << LPUART_ISR_TC_POS)
#define LPUART_ISR_RXFNE_BM                (0x1U << LPUART_ISR_RXFNE_POS)
#define LPUART_ISR_IDLE_BM                 (0x1U << LPUART_ISR_IDLE_POS)
#define LPUART_ISR_ORE_BM                  (0x1U << LPUART_ISR_ORE_POS)
#define LPUART_ISR_NE_BM                   (0x1U << LPUART_ISR_NE_POS)
#define LPUART_ISR_FE_BM                   (0x1U << LPUART_ISR_FE_POS)
#define LPUART_ICR_TCCF_BM                 (0x1U << LPUART_ICR_TCCF_POS)
#define LPUART_ICR_IDLECF_BM               (0x1U << LPUART_ICR_IDLECF_POS)
#define LPUART_ICR_ORECF_BM                (0x1U << LPUART_ICR_ORECF_POS)
#define LPUART_ICR_NECF_BM                 (0x1U << LPUART_ICR_NECF_POS)
#define LPUART_ICR_FECF_BM                 (0x1U << LPUART_ICR_FECF_POS)
#define LPUART_PRESC_PRESC_BM              (0xFU << LPUART_PRESC_PRESC_POS)

typedef enum {
    LPUART_WordLen_8 = 0x0U,
    LPUART_WordLen_9 = 0x1U,
    LPUART_WordLen_7 = 0x2U,
} LPUART_WordLen;

typedef enum {
    LPUART_Threshold_1_8 = 0x0U,
    LPUART_Threshold_1_4 = 0x1U,
    LPUART_Threshold_1_2 = 0x6U,
    LPUART_Threshold_3_4 = 0x3U,
    LPUART_Threshold_7_8 = 0x4U,
    LPUART_Threshold_Ful = 0x5U,
} LPUART_Threshold;

typedef enum {
    LPUART_Stop_1bit = 0x0U,
    LPUART_Stop_2bit = 0x2U,
} LPUART_Stop_Bits;

typedef enum {
    LPUART_ClkSrc_PClk      = 0x0U,
    LPUART_ClkSrc_SysClk    = 0x1U,
    LPUART_ClkSrc_HSI16     = 0x2U,
    LPUART_ClkSrc_LSE       = 0x3U,
} LPUART_ClkSrc;

typedef enum {
    LPUART_Presc_1      = 0x0U,
    LPUART_Presc_2      = 0x1U,
    LPUART_Presc_4      = 0x2U,
    LPUART_Presc_6      = 0x3U,
    LPUART_Presc_8      = 0x4U,
    LPUART_Presc_10     = 0x5U,
    LPUART_Presc_12     = 0x6U,
    LPUART_Presc_16     = 0x7U,
    LPUART_Presc_32     = 0x8U,
    LPUART_Presc_64     = 0x9U,
    LPUART_Presc_128    = 0xAU,
    LPUART_Presc_256    = 0xBU,
} LPUART_Presc;

__inline void enable_lpuart(void) {
    SET_BIT(RCC->RCC_APB1ENR2, RCC_APB1ENR2_LPUARTEN_POS);
}

__inline void disable_lpuart(void) {
    CLR_BIT(RCC->RCC_APB1ENR2, RCC_APB1ENR2_LPUARTEN_POS);
}

__inline void set_lpuart_wordlen(const LPUART_WordLen wordlen) {
    LPUART->LPUART_CR1 = (LPUART->LPUART_CR1 & ~LPUART_CR1_M1_BM) | ((wordlen & 0x2U) << LPUART_CR1_M1_POS);
    LPUART->LPUART_CR1 = (LPUART->LPUART_CR1 & ~LPUART_CR1_M0_BM) | ((wordlen & 0x1U) << LPUART_CR1_M0_POS);
}

__inline void enable_lpuart_fifo(void) {
    SET_BIT(LPUART->LPUART_CR1, LPUART_CR1_FIFOEN_POS);
}

__inline void disable_lpuart_fifo(void) {
    CLR_BIT(LPUART->LPUART_CR1, LPUART_CR1_FIFOEN_POS);
}

__inline void set_lpuart_tx_threshold(const LPUART_Threshold threshold) {
    LPUART->LPUART_CR3 = (LPUART->LPUART_CR3 & ~LPUART_CR3_TXFTCFG_BM) | (threshold << LPUART_CR3_TXFTCFG_POS);
}

__inline void set_lpuart_rx_threshold(const LPUART_Threshold threshold) {
    LPUART->LPUART_CR3 = (LPUART->LPUART_CR3 & ~LPUART_CR3_RXFTCFG_BM) | (threshold << LPUART_CR3_RXFTCFG_POS);
}

__inline void set_lpuart_stop(const LPUART_Stop_Bits stop_bits) {
    LPUART->LPUART_CR2 = (LPUART->LPUART_CR2 & ~LPUART_CR2_STOP_BM) | (stop_bits << LPUART_CR2_STOP_POS);
}

__inline void set_lpuart_baudrate(const uint32_t brr) {
    LPUART->LPUART_BRR = (LPUART->LPUART_BRR & ~LPUART_BRR_BRR_BM) | (brr << LPUART_BRR_BRR_POS);
}

__inline void set_lpuart_presc(const LPUART_Presc presc) {
    LPUART->LPUART_PRESC = (LPUART->LPUART_PRESC & ~LPUART_PRESC_PRESC_BM) | (presc << LPUART_PRESC_PRESC_POS);
}

__inline void set_lpuart_clksrc(const LPUART_ClkSrc clk_src) {
    RCC->RCC_CCIPR = (RCC->RCC_CCIPR & ~RCC_APB1ENR2_LPUARTEN_BM) | (clk_src << RCC_CCIPR_LPUART1SEL_POS);
}

#endif
