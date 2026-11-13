#include <stdint.h>
#include <drivers/nvic/nvic.h>

/* from the linker script */
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

int main(void);

// system fault handlers.
void reset_handler(void);
void nmi_handler(void)          __alias(default_handler); 
void hardfault_handler(void)    __alias(default_handler);
void memManage_handler(void)    __alias(default_handler);
void busfault_handler(void)     __alias(default_handler);
void usagefault_handler(void)   __alias(default_handler);
void pendSV_handler(void)       __alias(default_handler);
void sysTick_handler(void)      __alias(default_handler);

// NVIC interrupt handlers
void WWDG_IRQHandler(void) __alias(default_handler);
void PVD_PVM_IRQHandler(void) __alias(default_handler);
void RTC_TAMP_LSECSS_IRQHandler(void) __alias(default_handler);
void RTC_WKUP_IRQHandler(void) __alias(default_handler);
void FLASH_IRQHandler(void) __alias(default_handler);
void RCC_IRQHandler(void) __alias(default_handler);
void EXTI0_IRQHandler(void) __alias(default_handler);
void EXTI1_IRQHandler(void) __alias(default_handler);
void EXTI2_IRQHandler(void) __alias(default_handler);
void EXTI3_IRQHandler(void) __alias(default_handler);
void EXTI4_IRQHandler(void) __alias(default_handler);
void DMA1_Channel1_IRQHandler(void) __alias(default_handler);
void DMA1_Channel2_IRQHandler(void) __alias(default_handler);
void DMA1_Channel3_IRQHandler(void) __alias(default_handler);
void DMA1_Channel4_IRQHandler(void) __alias(default_handler);
void DMA1_Channel5_IRQHandler(void) __alias(default_handler);
void DMA1_Channel6_IRQHandler(void) __alias(default_handler);
void DMA1_Channel7_IRQHandler(void) __alias(default_handler);
void ADC1_2_IRQHandler(void) __alias(default_handler);
void USB_HP_IRQHandler(void) __alias(default_handler);
void USB_LP_IRQHandler(void) __alias(default_handler);
void FDCAN1_IT0_IRQHandler(void) __alias(default_handler);
void FDCAN1_IT1_IRQHandler(void) __alias(default_handler);
void EXTI9_5_IRQHandler(void) __alias(default_handler);
void TIM1_BRK_TIM15_IRQHandler(void) __alias(default_handler);
void TIM1_UP_TIM16_IRQHandler(void) __alias(default_handler);
void TIM1_TRG_COM_TIM17_IRQHandler(void) __alias(default_handler);
void TIM1_CC_IRQHandler(void) __alias(default_handler);
void TIM2_IRQHandler(void) __alias(default_handler);
void TIM3_IRQHandler(void) __alias(default_handler);
void TIM4_IRQHandler(void) __alias(default_handler);
void I2C1_EV_IRQHandler(void) __alias(default_handler);
void I2C1_ER_IRQHandler(void) __alias(default_handler);
void I2C2_EV_IRQHandler(void) __alias(default_handler);
void I2C2_ER_IRQHandler(void) __alias(default_handler);
void SPI1_IRQHandler(void) __alias(default_handler);
void SPI2_IRQHandler(void) __alias(default_handler);
void USART1_IRQHandler(void) __alias(default_handler);
void USART2_IRQHandler(void) __alias(default_handler);
void USART3_IRQHandler(void) __alias(default_handler);
void EXTI15_10_IRQHandler(void) __alias(default_handler);
void RTC_Alarm_IRQHandler(void) __alias(default_handler);
void USBWakeUp_IRQHandler(void) __alias(default_handler);
void TIM8_BRK_IRQHandler(void) __alias(default_handler);
void TIM8_UP_IRQHandler(void) __alias(default_handler);
void TIM8_TRG_COM_IRQHandler(void) __alias(default_handler);
void TIM8_CC_IRQHandler(void) __alias(default_handler);
void ADC3_IRQHandler(void) __alias(default_handler);
void LPTIM1_IRQHandler(void) __alias(default_handler);
void SPI3_IRQHandler(void) __alias(default_handler);
void UART4_IRQHandler(void) __alias(default_handler);
void UART5_IRQHandler(void) __alias(default_handler);
void TIM6_DAC_IRQHandler(void) __alias(default_handler);
void TIM7_IRQHandler(void) __alias(default_handler);
void DMA2_Channel1_IRQHandler(void) __alias(default_handler);
void DMA2_Channel2_IRQHandler(void) __alias(default_handler);
void DMA2_Channel3_IRQHandler(void) __alias(default_handler);
void DMA2_Channel4_IRQHandler(void) __alias(default_handler);
void DMA2_Channel5_IRQHandler(void) __alias(default_handler);
void UCPD1_IRQHandler(void) __alias(default_handler);
void COMP1_2_3_IRQHandler(void) __alias(default_handler);
void COMP4_IRQHandler(void) __alias(default_handler);
void CRS_IRQHandler(void) __alias(default_handler);
void SAI1_IRQHandler(void) __alias(default_handler);
void TIM20_BRK_IRQHandler(void) __alias(default_handler);
void TIM20_UP_IRQHandler(void) __alias(default_handler);
void TIM20_TRG_COM_IRQHandler(void) __alias(default_handler);
void TIM20_CC_IRQHandler(void) __alias(default_handler);
void FPU_IRQHandler(void) __alias(default_handler);
void FDCAN2_IT0_IRQHandler(void) __alias(default_handler);
void FDCAN2_IT1_IRQHandler(void) __alias(default_handler);
void RNG_IRQHandler(void) __alias(default_handler);
void LPUART1_IRQHandler(void) __alias(default_handler);
void I2C3_EV_IRQHandler(void) __alias(default_handler);
void I2C3_ER_IRQHandler(void) __alias(default_handler);
void DMAMUX_OVR_IRQHandler(void) __alias(default_handler);
void QUADSPI_IRQHandler(void) __alias(default_handler);
void DMA1_Channel8_IRQHandler(void) __alias(default_handler);
void DMA2_Channel6_IRQHandler(void) __alias(default_handler);
void DMA2_Channel7_IRQHandler(void) __alias(default_handler);
void DMA2_Channel8_IRQHandler(void) __alias(default_handler);
void CORDIC_IRQHandler(void) __alias(default_handler);
void FMAC_IRQHandler(void) __alias(default_handler);

uint32_t sysivt[] __section(".sysivt") = {
    (uint32_t)&_estack,
    (uint32_t)reset_handler,
    (uint32_t)nmi_handler,
    (uint32_t)hardfault_handler,
    (uint32_t)memManage_handler,
    (uint32_t)busfault_handler,
    (uint32_t)usagefault_handler,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)pendSV_handler,
    (uint32_t)sysTick_handler,
};

uint32_t ivt[STM32G_INT_COUNT] __section(".ivt") = {
    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_PVM_IRQHandler,
    (uint32_t)RTC_TAMP_LSECSS_IRQHandler,
    (uint32_t)RTC_WKUP_IRQHandler,
    (uint32_t)FLASH_IRQHandler,
    (uint32_t)RCC_IRQHandler,
    (uint32_t)EXTI0_IRQHandler,
    (uint32_t)EXTI1_IRQHandler,
    (uint32_t)EXTI2_IRQHandler,
    (uint32_t)EXTI3_IRQHandler,
    (uint32_t)EXTI4_IRQHandler,
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_IRQHandler,
    (uint32_t)DMA1_Channel3_IRQHandler,
    (uint32_t)DMA1_Channel4_IRQHandler,
    (uint32_t)DMA1_Channel5_IRQHandler,
    (uint32_t)DMA1_Channel6_IRQHandler,
    (uint32_t)DMA1_Channel7_IRQHandler,
    (uint32_t)ADC1_2_IRQHandler,
    (uint32_t)USB_HP_IRQHandler,
    (uint32_t)USB_LP_IRQHandler,
    (uint32_t)FDCAN1_IT0_IRQHandler,
    (uint32_t)FDCAN1_IT1_IRQHandler,
    (uint32_t)EXTI9_5_IRQHandler,
    (uint32_t)TIM1_BRK_TIM15_IRQHandler,
    (uint32_t)TIM1_UP_TIM16_IRQHandler,
    (uint32_t)TIM1_TRG_COM_TIM17_IRQHandler,
    (uint32_t)TIM1_CC_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM4_IRQHandler,
    (uint32_t)I2C1_EV_IRQHandler,
    (uint32_t)I2C1_ER_IRQHandler,
    (uint32_t)I2C2_EV_IRQHandler,
    (uint32_t)I2C2_ER_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t)USART2_IRQHandler,
    (uint32_t)USART3_IRQHandler,
    (uint32_t)EXTI15_10_IRQHandler,
    (uint32_t)RTC_Alarm_IRQHandler,
    (uint32_t)USBWakeUp_IRQHandler,
    (uint32_t)TIM8_BRK_IRQHandler,
    (uint32_t)TIM8_UP_IRQHandler,
    (uint32_t)TIM8_TRG_COM_IRQHandler,
    (uint32_t)TIM8_CC_IRQHandler,
    (uint32_t)ADC3_IRQHandler,
    (uint32_t)RESVD_MEM,
    (uint32_t)LPTIM1_IRQHandler,
    (uint32_t)RESVD_MEM,
    (uint32_t)SPI3_IRQHandler,
    (uint32_t)UART4_IRQHandler,
    (uint32_t)UART5_IRQHandler,
    (uint32_t)TIM6_DAC_IRQHandler,
    (uint32_t)TIM7_IRQHandler,
    (uint32_t)DMA2_Channel1_IRQHandler,
    (uint32_t)DMA2_Channel2_IRQHandler,
    (uint32_t)DMA2_Channel3_IRQHandler,
    (uint32_t)DMA2_Channel4_IRQHandler,
    (uint32_t)DMA2_Channel5_IRQHandler,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)UCPD1_IRQHandler,
    (uint32_t)COMP1_2_3_IRQHandler,
    (uint32_t)COMP4_IRQHandler,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)CRS_IRQHandler,
    (uint32_t)SAI1_IRQHandler,
    (uint32_t)TIM20_BRK_IRQHandler,
    (uint32_t)TIM20_UP_IRQHandler,
    (uint32_t)TIM20_TRG_COM_IRQHandler,
    (uint32_t)TIM20_CC_IRQHandler,
    (uint32_t)FPU_IRQHandler,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)FDCAN2_IT0_IRQHandler,
    (uint32_t)FDCAN2_IT1_IRQHandler,
    (uint32_t)RESVD_MEM,
    (uint32_t)RESVD_MEM,
    (uint32_t)RNG_IRQHandler,
    (uint32_t)LPUART1_IRQHandler,
    (uint32_t)I2C3_EV_IRQHandler,
    (uint32_t)I2C3_ER_IRQHandler,
    (uint32_t)DMAMUX_OVR_IRQHandler,
    (uint32_t)QUADSPI_IRQHandler,
    (uint32_t)DMA1_Channel8_IRQHandler,
    (uint32_t)DMA2_Channel6_IRQHandler,
    (uint32_t)DMA2_Channel7_IRQHandler,
    (uint32_t)DMA2_Channel8_IRQHandler,
    (uint32_t)CORDIC_IRQHandler,
    (uint32_t)FMAC_IRQHandler
};

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

/* stop-gap solution for exception handlers until the real ones are implemented */
void default_handler(void) {
    while(1);
}
