#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA0A8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        M2C_FIELD(arg0, s32*, 0x28) -= M2C_FIELD(arg0, s32*, 0x44);
        M2C_FIELD(arg0, s32*, 0x30) -= M2C_FIELD(arg0, s32*, 0x44);
    } else {
        M2C_FIELD(arg0, s32*, 0x18) += M2C_FIELD(arg0, s32*, 0x44);
        M2C_FIELD(arg0, s32*, 0x20) += M2C_FIELD(arg0, s32*, 0x44);
    }
    if (--M2C_FIELD(arg0, s32*, 0x38) == 0) {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}
