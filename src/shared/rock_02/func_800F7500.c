#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F7500(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFA0000;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
