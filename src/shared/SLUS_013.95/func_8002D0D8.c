#include "common.h"

extern u32 D_800737A8[];

s32 func_8002D0D8(s32 x, s32 y) {
    s32 sx;
    s32 sy;
    s32 q;
    register s32 v asm("$2");
    register s32 t asm("$3");
    s16 a;
    u32* p;

    v = y;
    if (x < 0) {
        sx = 1;
        x = -x;
    } else {
        sx = -1;
    }
    sy = 1;
    if (y < 0) {
        sy = -1;
        v = -y;
    }
    t = v >> 16;
    if (t != 0) {
        q = x / t;
        if (q <= 0xFFFF) {
            p = &D_800737A8[4];
            while (q < *p) {
                p--;
            }
            a = p - D_800737A8;
        } else {
            p = &D_800737A8[5];
            while (*p < q) {
                p++;
            }
            a = (p - D_800737A8) - 1;
        }
    } else {
        a = 8;
    }
    if (sy < 0) {
        if (sx > 0) {
            if (a == 8) {
                return 0;
            }
            return (u8)(a + 0x18);
        }
        return (u8)(0x18 - a);
    } else if (sx > 0) {
        return (u8)(8 - a);
    } else {
        return (u8)(a + 8);
    }
}
