#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */

void func_801EBFBC(void* arg0) {
    ((void (*)(void*, s32))func_8003F508)(arg0, 0x15);
    if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, u8*, 0x45) &= 0x7F;
        func_8003D510(0x21, 0x21, 0, 0);
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
