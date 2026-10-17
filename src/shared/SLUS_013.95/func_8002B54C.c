#include "common.h"

void func_8002B54C(u16* dst, u16* src, s32 count, s32 level) {
    u16 c;
    u32 r;
    u32 g;
    u32 b;
    u16 v;

    if (level >= 0x1F) {
        level = 0x1F;
    }
    if (level == 0x1F) {
        if (count > 0) {
            do {
                *dst = 0;
                count--;
                dst++;
            } while (count != 0);
        }
    } else if (count > 0) {
        do {
            c = *src;
            r = (c & 0x1F) << 8;
            g = (c & 0x3E0) << 8;
            b = (c & 0x7C00) << 8;
            r = (r - ((r * level) >> 5)) >> 8;
            r &= 0x1F;
            g = (g - ((g * level) >> 5)) >> 8;
            g &= 0x3E0;
            b = (b - ((b * level) >> 5)) >> 8;
            b &= 0x7C00;
            v = r | g | b | (c & 0x8000);
            src++;
            if (v == 0 && c != 0) {
                v = 0x8000;
            }
            *dst = v;
            count--;
            dst++;
        } while (count != 0);
    }
}
