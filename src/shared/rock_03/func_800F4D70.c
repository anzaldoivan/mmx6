#include "common.h"

extern u8 D_800F7BA0[][6];
extern s16 D_800F7E0E;

void func_800F4D70(u8* arg0) {
    u8 f;

    f = arg0[0x70];
    if ((f & 2) || (f & 1)) {
        D_800F7E0E = 0;
        *(s32*)(arg0 + 0x20) = 0;
        arg0[5] = D_800F7BA0[arg0[0x86]][arg0[0x87]++];
        arg0[6] = 0;
    }
}
