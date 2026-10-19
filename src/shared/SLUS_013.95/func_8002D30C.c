#include "common.h"

extern u16 D_80090E70;

s32 func_8002D30C(void) {
    s32 r;
    s32 ret;
    u32 t;
    u16 v;
    t = (u32)((D_80090E70 + D_80090E70 * 2) & 0xFFFF) >> 8;
    v = D_80090E70 + t;
    t <<= 8;
    v = (v & 0xFF) | t;
    D_80090E70 = v;
    r = v & 0xFF;
    ret = 1;
    if (r != 0) {
        ret = r;
    }
    return ret;
}
