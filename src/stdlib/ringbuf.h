#ifndef __RINGBUF_H__
#define __RINGBUF_H__

#include <stdint.h>
#include <utils/utils.h>

/* 256 byte ring buffer */
typedef struct {
    uint8_t buf[256];
    uint16_t wptr;
    uint16_t rptr;
} Ring_Buffer;

__inline Ring_Buffer init_ringbuf(void) {
    return (volatile Ring_Buffer){.wptr = 0, .rptr = 0};
}

__inline uint8_t ringbuf_push(volatile Ring_Buffer *const ringbuf, volatile const void *const databuf, const uint8_t datalen) {
    uint8_t i = 0;
    while ((i < datalen) && (ringbuf->wptr - ringbuf->rptr < 256)) { 
        ringbuf->buf[ringbuf->wptr & 0xFFU] = ((uint8_t*)databuf)[i++];
        ringbuf->wptr += 1;
    }
    return i;
}

__inline uint8_t ringbuf_pop(volatile Ring_Buffer *const ringbuf, volatile void *const databuf, const uint8_t databuf_capacity) {
    uint8_t i = 0;
    while ((i < databuf_capacity) && (ringbuf->rptr < ringbuf->wptr)) {
        ((uint8_t*)databuf)[i++] = ringbuf->buf[ringbuf->rptr & 0xFFU];
        ringbuf->rptr += 1;
    }
    return i;
}

#endif
