#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800972A3;

void func_800ECFA0(void* arg0) {
    D_800972A3 = 0;
    if (!(M2C_FIELD(arg0, u8*, 0x5F) & 0x10)) {
        M2C_FIELD(arg0, s8*, 1) = 6;
        M2C_FIELD(arg0, u8*, 2) = 0U;
        M2C_FIELD(arg0, s16*, 8) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}
