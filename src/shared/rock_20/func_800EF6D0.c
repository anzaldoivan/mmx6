#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);

void func_800EF6D0(void* arg0) {
    ((void (*)(s32))func_800139F4)(8);
    M2C_FIELD(arg0, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 1;
}
