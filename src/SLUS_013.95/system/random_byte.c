#include "common.h"

extern u16 D_80090E70;

// 0x8002D2D4 random_byte: steps the random seed and returns its low byte.
// basis: code src/shared/SLUS_013.95/random_byte.c:13 via=D_80090E70
// callers: drop_item, fire_charged_shot, func_8001D60C
s32 random_byte(void) {
    u16 v;
    u32 t;
    u32 hi;

    v = D_80090E70;
    t = (u16)(v + v * 2) >> 8;
    v += t;
    hi = t << 8;
    v &= 0xFF;
    v |= hi;
    D_80090E70 = v;
    return v & 0xFF;
}
