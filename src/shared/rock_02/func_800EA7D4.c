#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

#define SPAD4C_800EA7D4 (*(u8**)0x1F80004C)

void func_800EA7D4(void* arg0) {
    u8* p = arg0;
    ((void (*)(s32, s32, void*))func_80016C48)(2, 3, p);
    ((void (*)(void*, s32))func_800179A4)(p, 6);
    *(s32*)(p + 0x24) = 0x8000;
    *(s32*)(p + 0x2C) = 0;
    SPAD4C_800EA7D4[0x82] = 1;
    *(s16*)(p + 0x7C) = 0x3C;
    p[6]++;
}

#undef SPAD4C_800EA7D4
