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

#endif
