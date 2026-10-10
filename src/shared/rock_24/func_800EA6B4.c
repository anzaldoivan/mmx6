#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA6B4(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 0x67) == 0) &&
        !(M2C_FIELD(arg0, u8*, 0x70) & 8)) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
    }
}
