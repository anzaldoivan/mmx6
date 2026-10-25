#include "common.h"

extern s32 D_800F5D08;
extern s32 D_800F5D18;

void func_800EF740(u8* arg0) {
    s8 t;
    s8 v;

    if ((u8)++arg0[0x88] >= 0x3D) {
        *(s32**)(arg0 + 0x54) = &D_800F5D08;
        *(s32**)(arg0 + 0x50) = &D_800F5D18;
        t = arg0[2];
        arg0[0x88] = 0;
        if (t == 0) {
            v = 1;
        common: {
            // !FAKE: depin: dropping it breaks the match (26/29)
            register s32 k asm("$3") = 0x2000;
            arg0[6] = v;
            *(s32*)(arg0 + 0x2C) = k;
        }
            return;
        }
        if (t == 1) {
            v = 2;
            goto common;
        }
        arg0[6] = 4;
    }
}
