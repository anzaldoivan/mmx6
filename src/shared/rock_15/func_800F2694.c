#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F2694(u8* arg0) {
    func_800179A4(arg0, 4);
    *(s16*)(arg0 + 0x86) = 0x12C;
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}
