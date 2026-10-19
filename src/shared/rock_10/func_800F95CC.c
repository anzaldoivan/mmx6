#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F95CC(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        arg0[6] = arg0[6] + 1;
    }
}
