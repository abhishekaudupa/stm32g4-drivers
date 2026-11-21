#include <stdint.h>
#include <utils/utils.h>
#include <drivers/rcc/rcc.h>
#include <drivers/gpio/gpio.h>
#include <drivers/nvic/nvic.h>
#include <drivers/systick/systick.h>
#include <drivers/asm/asm.h>
#include <drivers/lpuart/lpuart.h>
#include <board/nucleog491re/nucleog491re.h>

void sysTick_handler() {
    TGL_BIT(GPIOA->GPIO_ODR, LD2);
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
    Systick_Config config = { .load_val = 0x2faf08, .interrupt = 1, .clk_src = SysTick_Clk_AHB_8 };
    prep_user_led();
    start_systick(config);
}

void init_lpuart(void) {
    volatile uint32_t dummy __unused;
    
    enable_gpio('A');
    set_gpio_mode(GPIOA, GPIO_P02, GPIO_MODE_AF);
    set_gpio_otype(GPIOA, GPIO_P02, GPIO_OTYPE_PP);
    set_gpio_pupd(GPIOA, GPIO_P02, GPIO_PP_NO);
    set_gpio_afrl(GPIOA, GPIO_P02, GPIO_AF12);
    set_gpio_mode(GPIOA, GPIO_P03, GPIO_MODE_AF);
    set_gpio_otype(GPIOA, GPIO_P03, GPIO_OTYPE_PP);
    set_gpio_pupd(GPIOA, GPIO_P03, GPIO_PP_NO);
    set_gpio_afrl(GPIOA, GPIO_P03, GPIO_AF12);

    enable_lpuart_clock();
    set_lpuart_wordlen(LPUART_WordLen_8);
    set_lpuart_clksrc(LPUART_ClkSrc_SysClk);
    set_lpuart_presc(LPUART_Presc_1);
    set_lpuart_baudrate(0x1b207); //115200
    set_lpuart_stop(LPUART_Stop_1bit);
    enable_lpuart();
    enable_lpuart_transmit();

    LPUART->LPUART_TDR = 'A';
    // check TXE, should be off.
    dummy = TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_TXE_POS);
    while(!TST_BIT(LPUART->LPUART_ISR, LPUART_ISR_TC_POS));
}

int main(void) {
    start_pll_50_MHz();
    init_lpuart();
    return 0;
}
