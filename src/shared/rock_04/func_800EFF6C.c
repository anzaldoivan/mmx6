#include "common.h"

extern s32 D_800F6D90;
extern s32 D_800F6D9C;

void func_800EFF6C(u8* arg0) {
    arg0[3] ^= 1;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s32**)(arg0 + 0x54) = &D_800F6D9C;
        *(s32**)(arg0 + 0x50) = &D_800F6D90;
        arg0[6]++;
    }
}
