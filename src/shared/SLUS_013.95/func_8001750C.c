#include "common.h"

extern s32* D_80097778[];
s32 func_8005AD40(u8);
s32 func_8005BC14(u8, s32, s32);

void func_8001750C(u8 arg0, u8 arg1) {
    u8 i;
    u8 v;
    s8 n;
    s32* p;

    if (arg0 == 0xFF) {
        for (i = 0; i < 0x18; i++) {
            func_8005BC14(i, 0, 0);
            func_8005AD40(i);
        }
        return;
    }
    p = D_80097778[arg0];
    p += arg1;
    v = ((u8*)p)[3];
    i = v & 0x1F;
    for (n = (v & 0x60) >> 5; n >= 0; n--) {
        func_8005BC14(i, 0, 0);
        func_8005AD40(i);
        i++;
    }
}
