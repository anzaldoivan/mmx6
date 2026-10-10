#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F29C8(void* arg0) {
    if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
}
