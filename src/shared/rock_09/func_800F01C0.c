#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800F01C0(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
