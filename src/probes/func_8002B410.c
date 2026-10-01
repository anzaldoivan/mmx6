/* Probe (phase 1.4 T6): divu by a variable, mult/mflo hazard, 5th arg on the stack. Game TU 120A0. */
#include "common.h"

void func_8002B410(u16* dst, u16* src, s32 n, s32 num, s32 den) {
    u32 c;
    u32 r;
    u32 g;
    u32 b;
    u16 out;
    s32 i;

    if (num >= den) {
        num = den;
    }
    if (num == den) {
        for (i = 0; i < n; i++) {
            *dst++ = 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            c = *src++;
            r = (c & 0x1F) << 8;
            g = (c & 0x3E0) << 8;
            b = (c & 0x7C00) << 8;
            r = (r - r * num / den) >> 8;
            g = (g - g * num / den) >> 8;
            b = (b - b * num / den) >> 8;
            r &= 0x1F;
            g &= 0x3E0;
            b &= 0x7C00;
            out = r | g | b | (c & 0x8000);
            if (out == 0 && c != 0) {
                out = 0x8000;
            }
            *dst++ = out;
        }
    }
}
