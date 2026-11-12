#ifndef __UTILS_H__
#define __UTILS_H__

/* compiler directives */
#define __alias(default_func)                  __attribute__((weak, alias(#default_func)))
#define __section(sec)                         __attribute__((section(#sec)))
#define __unused                               __attribute__((unused))
#define __packed                               __attribute__((packed))
#define __inline                               static inline

#define RESVD_MEM                              0

/* bit manipulation macros. */
#define BIT(pos)                               (0x1U << (pos))
#define BITS(pos, bitcount)                    ((BIT(bitcount) - 1) << (pos))
#define SET_BITS(reg, pos, bitcount)           ((reg) = ((reg) |  BITS((pos), (bitcount))))
#define CLR_BITS(reg, pos, bitcount)           ((reg) = ((reg) & ~BITS((pos), (bitcount))))
#define TOG_BITS(reg, pos, bitcount)           ((reg) = ((reg) ^  BITS((pos), (bitcount))))
#define SET_BIT(reg, pos)                      SET_BITS(reg, pos, 1)
#define CLR_BIT(reg, pos)                      CLR_BITS(reg, pos, 1)
#define TOG_BIT(reg, pos)                      TOG_BITS(reg, pos, 1)
#define TEST_BIT(reg, pos)                     ((reg) & BITS((pos), 1))

/* modify bitcount number of bits at pos with val */
#define MODIFY_BITS(reg, pos, bitcount, val)   (reg = (CLR_BITS((reg), (pos), (bitcount)) | ((val) << (pos))))

#endif
