#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80097427;

void func_800EFA40(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0xA) = 0x1C;
    M2C_FIELD(arg0, s16*, 0xE) = (s16)((D_80097427 * 0x10) + 0x2E);
}
