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
#define SET_BIT(reg, pos)                      ((reg) = ((reg) |  BIT(pos)))
#define CLR_BIT(reg, pos)                      ((reg) = ((reg) & ~BIT(pos)))
#define TGL_BIT(reg, pos)                      ((reg) = ((reg) ^  BIT(pos)))
#define TST_BIT(reg, pos)                      ((reg) & BIT(pos))

#define RMW(reg, bitmask, bitpos, val)         (reg & ~bitmask) | (val << bitpos)

#endif
