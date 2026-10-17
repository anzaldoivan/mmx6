#include "common.h"

s32 func_80018BE0(s32 arg0, u8* arg1) {
    u16* src;
    u16* dst;
    u16* p;
    u32 flags;
    u32 bit;
    s32 n;
    u32 len;
    u32 off;
    u32 t;
    u16 tmp;

    src = (u16*)arg0;
    dst = (u16*)arg1;
    for (;;) {
        flags = *src++;
        bit = 0x8000;
        n = 16;
        do {
            if (!(bit & flags)) {
                tmp = *src++;
                bit >>= 1;
                n--;
                *dst++ = tmp;
                continue;
            }
            off = *src++;
            t = off & 0xF800;
            if (t != 0) {
                len = t >> 11;
                off &= 0x7FF;
            } else {
                len = *src++;
            }
            if ((len | off) == 0) {
                return;
            }
            if (off == 0) {
                bit >>= 1;
                n--;
                while (len != 0) {
                    *dst++ = 0;
                    len--;
                }
            } else {
                p = dst - off;
                bit >>= 1;
                n--;
                while (len != 0) {
                    *dst++ = *p++;
                    len--;
                }
            }
        } while (n != 0);
    }
}
