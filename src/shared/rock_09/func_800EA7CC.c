#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA7CC(void* arg0) {
    if (!(M2C_FIELD(arg0, u8*, 0x70) & 8) &&
        (M2C_FIELD(arg0, s8*, 0x67) == 0)) {
        s32 v;
        v = 4;
        M2C_FIELD(arg0, u8*, 0x5) = v;
        v = 0x4200;
        M2C_FIELD(arg0, s32*, 0x2C) = v;
        v = 1;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 0x67) = v;
    }
}
