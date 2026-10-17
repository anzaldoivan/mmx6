#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F4E34(void* arg0) {
    ((void (*)(s32, s32, void*))func_80016C48)(2, 0x21, arg0);
    ((void (*)(void*, s32))func_800179A4)(arg0, 0x19);
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, u8*, 6) += 2;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4000;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
