#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F58E8(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
        *(s16*)(arg0 + 0x7C) = 0x14;
        arg0[6] = arg0[6] + 1;
    }
}
