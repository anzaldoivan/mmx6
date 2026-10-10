#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800CD3F0;

void func_80025F84(void) {
    M2C_FIELD(&D_800CD3F0, s8*, 0) = 5;
    M2C_FIELD(&D_800CD3F0, s8*, 1) = 6;
    M2C_FIELD(&D_800CD3F0, s8*, 2) = 7;
    M2C_FIELD(&D_800CD3F0, s8*, 3) = 8;
}
