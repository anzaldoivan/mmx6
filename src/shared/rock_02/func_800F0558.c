#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0558(void* arg0) {
    s32 idx;
    s32 base;

    M2C_FIELD(arg0, s32*, 0x2C) = 0x8000;
    idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    base = SPAD20;
    M2C_FIELD(arg0, s32*, 0x3C) = base + *(s32*)(idx * 4 + base);
    ((void (*)(void*, s32))func_800179A4)(arg0, 2);
    M2C_FIELD(arg0, u8*, 0x88) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
