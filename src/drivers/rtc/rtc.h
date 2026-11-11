#ifndef __RTC_H__
#define __RTC_H__

#include <stdint.h>
#include <utils/utils.h>

typedef struct __packed {
    uint32_t RTC_TR;
    uint32_t RTC_DR;
    uint32_t RTC_SSR;
    uint32_t RTC_ICSR;
    uint32_t RTC_PRER;
    uint32_t RTC_WUTR;
    uint32_t RTC_CR;
    uint32_t RTC_WPR;
    uint32_t RTC_CALR;
    uint32_t RTC_SHIFTR;
    uint32_t RTC_TSTR;
    uint32_t RTC_TSDR;
    uint32_t RTC_TSSSR;
    uint32_t RTC_ALRMR;
    uint32_t RTC_ALRMASSR;
    uint32_t RTC_ALRMBR;
    uint32_t RTC_ALRMBSSR;
    uint32_t RTC_SR;
    uint32_t RTC_MISR;
    uint32_t RTC_SCR;
} RTC;

#define RTC ((volatile RCC*) 0x40002800)

#endif
