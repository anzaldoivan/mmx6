#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EB764(void* arg0) {
    SPAD[0x88] = 3;
    ((void (*)(void*, s32))func_800179A4)(arg0, 4);
    M2C_FIELD(arg0, u8*, 0x6)++;
}
