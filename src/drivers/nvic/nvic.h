#ifndef __NVIC_H__
#define __NVIC_H__

#include <stdint.h>
#include <utils/utils.h>

#define STM32G_INT_COUNT 102

// system fault handlers.
void reset_handler(void);
void nmi_handler(void)         ; 
void hardfault_handler(void)   ;
void memManage_handler(void)   ;
void busfault_handler(void)    ;
void usagefault_handler(void)  ;
void pendSV_handler(void)      ;
void sysTick_handler(void)     ;

// NVIC interrupt handlers
void WWDG_IRQHandler(void);
void PVD_PVM_IRQHandler(void);
void RTC_TAMP_LSECSS_IRQHandler(void);
void RTC_WKUP_IRQHandler(void);
void FLASH_IRQHandler(void);
void RCC_IRQHandler(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void DMA1_Channel1_IRQHandler(void);
void DMA1_Channel2_IRQHandler(void);
void DMA1_Channel3_IRQHandler(void);
void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel5_IRQHandler(void);
void DMA1_Channel6_IRQHandler(void);
void DMA1_Channel7_IRQHandler(void);
void ADC1_2_IRQHandler(void);
void USB_HP_IRQHandler(void);
void USB_LP_IRQHandler(void);
void FDCAN1_IT0_IRQHandler(void);
void FDCAN1_IT1_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void TIM1_BRK_TIM15_IRQHandler(void);
void TIM1_UP_TIM16_IRQHandler(void);
void TIM1_TRG_COM_TIM17_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void I2C2_EV_IRQHandler(void);
void I2C2_ER_IRQHandler(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
void RTC_Alarm_IRQHandler(void);
void USBWakeUp_IRQHandler(void);
void TIM8_BRK_IRQHandler(void);
void TIM8_UP_IRQHandler(void);
void TIM8_TRG_COM_IRQHandler(void);
void TIM8_CC_IRQHandler(void);
void ADC3_IRQHandler(void);
void LPTIM1_IRQHandler(void);
void SPI3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);
void DMA2_Channel1_IRQHandler(void);
void DMA2_Channel2_IRQHandler(void);
void DMA2_Channel3_IRQHandler(void);
void DMA2_Channel4_IRQHandler(void);
void DMA2_Channel5_IRQHandler(void);
void UCPD1_IRQHandler(void);
void COMP1_2_3_IRQHandler(void);
void COMP4_IRQHandler(void);
void CRS_IRQHandler(void);
void SAI1_IRQHandler(void);
void TIM20_BRK_IRQHandler(void);
void TIM20_UP_IRQHandler(void);
void TIM20_TRG_COM_IRQHandler(void);
void TIM20_CC_IRQHandler(void);
void FPU_IRQHandler(void);
void FDCAN2_IT0_IRQHandler(void);
void FDCAN2_IT1_IRQHandler(void);
void RNG_IRQHandler(void);
void LPUART1_IRQHandler(void);
void I2C3_EV_IRQHandler(void);
void I2C3_ER_IRQHandler(void);
void DMAMUX_OVR_IRQHandler(void);
void QUADSPI_IRQHandler(void);
void DMA1_Channel8_IRQHandler(void);
void DMA2_Channel6_IRQHandler(void);
void DMA2_Channel7_IRQHandler(void);
void DMA2_Channel8_IRQHandler(void);
void CORDIC_IRQHandler(void);
void FMAC_IRQHandler(void);

typedef struct {
    uint32_t NVIC_IPR0;
    uint32_t NVIC_IPR1;
    uint32_t NVIC_IPR2;
    uint32_t NVIC_IPR3;
    uint32_t NVIC_IPR4;
    uint32_t NVIC_IPR5;
    uint32_t NVIC_IPR6;
    uint32_t NVIC_IPR7;
    uint32_t NVIC_IPR8;
    uint32_t NVIC_IPR9;
    uint32_t NVIC_IPR10;
    uint32_t NVIC_IPR11;
    uint32_t NVIC_IPR12;
    uint32_t NVIC_IPR13;
    uint32_t NVIC_IPR14;
    uint32_t NVIC_IPR15;
    uint32_t NVIC_IPR16;
    uint32_t NVIC_IPR17;
    uint32_t NVIC_IPR18;
    uint32_t NVIC_IPR19;
    uint32_t NVIC_IPR20;
    uint32_t NVIC_IPR21;
    uint32_t NVIC_IPR22;
    uint32_t NVIC_IPR23;
    uint32_t NVIC_IPR24;
    uint32_t NVIC_IPR25;
    uint32_t NVIC_IPR26;
    uint32_t NVIC_IPR27;
    uint32_t NVIC_IPR28;
    uint32_t NVIC_IPR29;
    uint32_t NVIC_IPR30;
    uint32_t NVIC_IPR31;
    uint32_t NVIC_IPR32;
    uint32_t NVIC_IPR33;
    uint32_t NVIC_IPR34;
    uint32_t NVIC_IPR35;
    uint32_t NVIC_IPR36;
    uint32_t NVIC_IPR37;
    uint32_t NVIC_IPR38;
    uint32_t NVIC_IPR39;
    uint32_t NVIC_IPR40;
    uint32_t NVIC_IPR41;
    uint32_t NVIC_IPR42;
    uint32_t NVIC_IPR43;
    uint32_t NVIC_IPR44;
    uint32_t NVIC_IPR45;
    uint32_t NVIC_IPR46;
    uint32_t NVIC_IPR47;
    uint32_t NVIC_IPR48;
    uint32_t NVIC_IPR49;
    uint32_t NVIC_IPR50;
    uint32_t NVIC_IPR51;
    uint32_t NVIC_IPR52;
    uint32_t NVIC_IPR53;
    uint32_t NVIC_IPR54;
    uint32_t NVIC_IPR55;
    uint32_t NVIC_IPR56;
    uint32_t NVIC_IPR57;
    uint32_t NVIC_IPR58;
    uint32_t NVIC_IPR59;
} NVIC_IPR;

typedef struct {
    uint32_t NVIC_ISER0;
    uint32_t NVIC_ISER1;
    uint32_t NVIC_ISER2;
    uint32_t NVIC_ISER3;
    uint32_t NVIC_ISER4;
    uint32_t NVIC_ISER5;
    uint32_t NVIC_ISER6;
    uint32_t NVIC_ISER7;
} NVIC_ISER;

typedef struct {
    uint32_t NVIC_ICER0;
    uint32_t NVIC_ICER1;
    uint32_t NVIC_ICER2;
    uint32_t NVIC_ICER3;
    uint32_t NVIC_ICER4;
    uint32_t NVIC_ICER5;
    uint32_t NVIC_ICER6;
    uint32_t NVIC_ICER7;
} NVIC_ICER;

typedef struct {
    uint32_t NVIC_ISPR0;
    uint32_t NVIC_ISPR1;
    uint32_t NVIC_ISPR2;
    uint32_t NVIC_ISPR3;
    uint32_t NVIC_ISPR4;
    uint32_t NVIC_ISPR5;
    uint32_t NVIC_ISPR6;
    uint32_t NVIC_ISPR7;
} NVIC_ISPR;

typedef struct {
    uint32_t NVIC_ICPR0;
    uint32_t NVIC_ICPR1;
    uint32_t NVIC_ICPR2;
    uint32_t NVIC_ICPR3;
    uint32_t NVIC_ICPR4;
    uint32_t NVIC_ICPR5;
    uint32_t NVIC_ICPR6;
    uint32_t NVIC_ICPR7;
} NVIC_ICPR;

typedef struct {
    uint32_t NVIC_IABR0;
    uint32_t NVIC_IABR1;
    uint32_t NVIC_IABR2;
    uint32_t NVIC_IABR3;
    uint32_t NVIC_IABR4;
    uint32_t NVIC_IABR5;
    uint32_t NVIC_IABR6;
    uint32_t NVIC_IABR7;
} NVIC_IABR;

#define NVIC_ISER ((volatile NVIC_ISER*) 0xE000E100)
#define NVIC_ICER ((volatile NVIC_ICER*) 0xE000E180)
#define NVIC_ISPR ((volatile NVIC_ISPR*) 0xE000E200)
#define NVIC_ICPR ((volatile NVIC_ICPR*) 0xE000E280)
#define NVIC_IABR ((volatile NVIC_IABR*) 0xE000E300)
#define NVIC_IPR  ((volatile NVIC_IPR*)  0xE000E400)
#define NVIC_STIR (*(volatile uint32_t*) 0xE000EF00)

#endif
