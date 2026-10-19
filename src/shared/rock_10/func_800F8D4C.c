#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F8D4C(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        func_800179A4(arg0, 0xF);
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        arg0[7] = 2;
        arg0[6] = arg0[6] + 1;
    }
}
