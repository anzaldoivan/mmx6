#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F6BE8;

void func_800F3E8C(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
        M2C_FIELD(arg0, s8*, 6) = 6;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < D_800F6BE8) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 6) = 4;
}
