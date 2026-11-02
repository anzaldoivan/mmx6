#include "common.h"

#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK); /* extern */

#define SPAD (*(u8**)0x1F80004C)

void func_800EB6C4(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 2);
    SPAD[0x88] = 2;
    arg0[6]++;
}
