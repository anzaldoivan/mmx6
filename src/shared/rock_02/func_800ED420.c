#include "common.h"

#define SPAD4C (*(u8**)0x1F80004C)

void func_800ED420(u8* a0) {
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x28) = 0;
    *(s32*)(a0 + 0x24) = 0;
    *(s32*)(a0 + 0x2C) = 0;
    a0[6]++;
    if (*(s8*)(a0 + 2) == 3) {
        SPAD4C[0x80] = 1;
    } else {
        SPAD4C[0x80] = 20;
    }
}
