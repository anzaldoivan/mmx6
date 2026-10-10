#include "common.h"

extern u8 D_80097427;
extern u8 D_800F0C04[][3];

void func_800EFA6C(u8* arg0) {
    u8 v;
    u8 w;

    v = arg0[0x57];
    arg0[3] = 1;
    if (v != 0) {
        if ((v - 1) == D_80097427) {
            *(s16*)(arg0 + 0x42) = 0x784C;
            return;
        }
        w = D_800F0C04[arg0[2]][1];
        *(s16*)(arg0 + 0x42) = (w & 0xF) | (((w >> 4) + 0x1E0) << 6);
    }
}
