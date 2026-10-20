#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800FC39C(void* arg0) {
    ((void (*)(void*, s32))func_800179A4)(arg0, 0);
    ((void (*)(void*))func_80017A04)(arg0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
