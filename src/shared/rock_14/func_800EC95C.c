#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800970A5;

void func_800EC95C(void* arg0) {
    if (D_800970A5 == 0x14) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x2A;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
