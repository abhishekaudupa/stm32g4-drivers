#include <stdint.h>
#include <board/nucleog491re/nucleog491re.h>
#include <drivers/asm/asm.h>
#include <drivers/gpio/gpio.h>
#include <drivers/lpuart/lpuart.h>
#include <drivers/nvic/nvic.h>
#include <drivers/rcc/rcc.h>
#include <drivers/systick/systick.h>
#include <utils/utils.h>

void sysTick_handler() { 
    TGL_BIT(GPIOA->GPIO_ODR, LD2); 
}

void LPUART1_IRQHandler(void) {
    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_TEACK_POS)) {
    }
    
    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_REACK_POS)) {
    }

    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_BUSY_POS)) {
    }
    
    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_TXE_POS)) {
    }
    
    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_TC_POS)) {
    }
    
    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_RXNE_POS)) {
    }
    
    if (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_IDLE_POS)) {
    }
}

void start_pll_50_MHz(void) {
    enable_rcc_hse_oscext();
    disable_rcc_pll();
    set_rcc_pll_source(RCC_PLL_Src_HSE);
    set_rcc_pllm_div(HSE24_MATCH_PLLM_050000000);
    set_rcc_plln_mul(HSE24_MATCH_PLLN_050000000);
    set_rcc_pllr_div(HSE24_MATCH_PLLR_050000000);
    enable_rcc_pllr();
    enable_rcc_pll();
    set_rcc_sysclk_source(SysClk_Src_PLL);
    disable_rcc_hsi();
}

void start_systick_500_ms(void) {
    Systick_Config config = {.load_val = 0x2faf08, .interrupt = 1, .clk_src = SysTick_Clk_AHB_8};
    prep_user_led();
    start_systick(config);
}

void init_lpuart(const LPUART_Config config) {
    enable_lpuart_clock();
    set_lpuart_wordlen(config.wordlen);
    set_lpuart_clksrc(config.clksrc);
    set_lpuart_presc(config.presc);
    set_lpuart_baudrate(config.baudrate);
    set_lpuart_stop(config.stopbit);
    if (config.fifomode)
        enable_lpuart_fifo();
    enable_lpuart();
    lpuart_send_idle_frame();
}

void lpuart_transmit_data(const uint8_t data) {
    while (TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_TXE_POS) == 0); 
    LPUART->LPUART_TDR = data;
}

int main(void) {
    LPUART_Config lpuart_config = {.baudrate = 0x1b207, // 115200 baud
        .clksrc   = LPUART_ClkSrc_SysClk,
        .presc    = LPUART_Presc_1,
        .stopbit  = LPUART_Stop_1bit,
        .wordlen  = LPUART_WordLen_8,
        .fifomode = 1};

    start_pll_50_MHz();
    enable_lpuart_pins();
    init_lpuart(lpuart_config);

    char *data = "/stm32g491re@abhishek> ";
    for (int i = 0; data[i]; ++i)
        lpuart_transmit_data(data[i]);
    return 0;
}
