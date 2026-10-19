#include "common.h"

extern u16 D_80090E70;

s32 func_8002D2D4(void) {
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
