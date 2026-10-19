#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA124(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x2) == 2) {
        M2C_FIELD(arg0, s32*, 0x14) += M2C_FIELD(arg0, s32*, 0x40);
        M2C_FIELD(arg0, s32*, 0x2C) += M2C_FIELD(arg0, s32*, 0x40);
    } else {
        M2C_FIELD(arg0, s32*, 0x1C) -= M2C_FIELD(arg0, s32*, 0x40);
        M2C_FIELD(arg0, s32*, 0x24) -= M2C_FIELD(arg0, s32*, 0x40);
    }
    if (--M2C_FIELD(arg0, s32*, 0x38) == 0) {
        M2C_FIELD(arg0, u8*, 0x4) += 1;
    }
}
