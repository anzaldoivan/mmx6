#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F33C4(u8* e) {
    ((void (*)(void*, s32))func_800179A4)(e, 0);
    *(s16*)(e + 0x7C) = 0x78;
    e[6]++;
}
