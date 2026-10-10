#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80097427;

void func_80048A50(void* arg0) {
    s16 var_v0;

    if (M2C_FIELD(arg0, s16*, 0xE) != 0x30) {
        var_v0 = 0x7C10;
        if (M2C_FIELD(arg0, s8*, 7) == D_80097427) {
            var_v0 = 0x7C12;
        }
        M2C_FIELD(arg0, s16*, 0x42) = var_v0;
    }
    M2C_FIELD(arg0, s8*, 3) = 1;
}
