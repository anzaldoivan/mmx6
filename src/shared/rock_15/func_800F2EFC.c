#include "common.h"

extern u8 D_800F6DF8[];

void func_800F2EFC(u8* arg0) {
    s32 t;
    u8 v;

    if (*(s8*)(arg0 + 0x45) == 1) {
        if (*(s16*)(arg0 + 0x7E) != 0) {
            *(s16*)(arg0 + 0x7C) = 10;
            arg0[6]++;
            return;
        }
        t = arg0[0x89] + 1;
        arg0[0x89] = t;
        v = D_800F6DF8[(s8)t + *(s8*)(arg0 + 0x88) * 4];
        arg0[6] = 0;
        arg0[0x8B] = 0;
        arg0[5] = v;
    }
}
