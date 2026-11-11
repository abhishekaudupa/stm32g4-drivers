#ifndef __SPECIAL_H__
#define __SPECIAL_H__

#include <stdint.h>
#include <utils/utils.h>

__inline uint32_t read_reg_apsr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, apsr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_ipsr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, ipsr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_epsr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, epsr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_iepsr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, iepsr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_iapsr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, iapsr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_eapsr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, eapsr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_psr(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, psr" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_msp(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, msp" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_psp(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, psp" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_primask(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, primask" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_basepri(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, basepri" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_basepri_max(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, basepri_max" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_faultmask(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, faultmask" : "=r"(u32reg));
    return u32reg;
}

__inline uint32_t read_reg_control(void) {
    uint32_t u32reg = 0;
    __asm__ volatile ("mrs %0, control" : "=r"(u32reg));
    return u32reg;
}

__inline void write_reg_apsr(const uint32_t u32) {
    __asm__ volatile ("msr apsr, %0" : : "r"(u32));
}

__inline void write_reg_ipsr(const uint32_t u32) {
    __asm__ volatile ("msr ipsr, %0" : : "r"(u32));
}

__inline void write_reg_epsr(const uint32_t u32) {
    __asm__ volatile ("msr epsr, %0" : : "r"(u32));
}

__inline void write_reg_iepsr(const uint32_t u32) {
    __asm__ volatile ("msr iepsr, %0" : : "r"(u32));
}

__inline void write_reg_iapsr(const uint32_t u32) {
    __asm__ volatile ("msr iapsr, %0" : : "r"(u32));
}

__inline void write_reg_eapsr(const uint32_t u32) {
    __asm__ volatile ("msr eapsr, %0" : : "r"(u32));
}

__inline void write_reg_psr(const uint32_t u32) {
    __asm__ volatile ("msr psr, %0" : : "r"(u32));
}

__inline void write_reg_msp(const uint32_t u32) {
    __asm__ volatile ("msr msp, %0" : : "r"(u32));
}

__inline void write_reg_psp(const uint32_t u32) {
    __asm__ volatile ("msr psp, %0" : : "r"(u32));
}

__inline void write_reg_primask(const uint32_t u32) {
    __asm__ volatile ("msr primask, %0" : : "r"(u32));
}

__inline void write_reg_basepri(const uint32_t u32) {
    __asm__ volatile ("msr basepri, %0" : : "r"(u32));
}

__inline void write_reg_basepri_max(const uint32_t u32) {
    __asm__ volatile ("msr basepri_max, %0" : : "r"(u32));
}

__inline void write_reg_faultmask(const uint32_t u32) {
    __asm__ volatile ("msr primask, %0" : : "r"(u32));
}

__inline void write_reg_control(const uint32_t u32) {
    __asm__ volatile ("msr control, %0" : : "r"(u32));
}

__inline void data_memory_barrier(void) {
    __asm__ volatile ("dmb");
}

__inline void data_sync_barrier(void) {
    __asm__ volatile ("dsb");
}

__inline void instruction_sync_barrier(void) {
    __asm__ volatile ("isb");
}

__inline void enable_exceptions(void) {
    __asm__ volatile ("cpsie i" ::: "memory");
    __asm__ volatile ("cpsie f" ::: "memory");
}

__inline void disable_irq(void) {
    __asm__ volatile ("cpsid i" ::: "memory");
}

__inline void disable_exceptions(void) {
    __asm__ volatile ("cpsid f" ::: "memory");
}

#endif
