#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800FB6B4(void* arg0) {
    ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 1);
    M2C_FIELD(arg0, u8*, 0x89) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
