#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F0BDC(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
