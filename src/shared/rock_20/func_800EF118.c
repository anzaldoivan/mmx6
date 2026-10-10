#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCEF8;

void func_800EF118(void* arg0) {
    D_800CCEF8 = 0x5F;
    M2C_FIELD(arg0, s8*, 1) = 3;
    M2C_FIELD(arg0, s8*, 2) = 0;
}
