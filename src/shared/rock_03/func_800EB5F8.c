#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define SPAD (*(u8**)0x1F80004C)

void func_800EB5F8(u8* arg0) {
    SPAD[0x88] = 1;
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    *(u16*)(arg0 + 0x7C) = 0xB4;
    arg0[6] = arg0[6] + 1;
}
