#include <stdint.h>
#include <stddef.h>
#include <stdlib/mem.h>

void* memcpy(void *dst, const void *src, size_t num) {
    for (size_t i = 0; i < num; ++i) {
        *((uint8_t*)dst + i) = *((uint8_t*)src + i);
    }
    return dst;
}

void *memset(void *s, int c, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        *((uint8_t*)s + i) = c;
    }
    return s;
}
