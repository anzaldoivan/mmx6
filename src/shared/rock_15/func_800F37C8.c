#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F37C8(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, s16*, 0x84) = 0x3C;
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s8*, 0x8A) = 0;
        M2C_FIELD(arg0, s8*, 0x8B) = 0;
        M2C_FIELD(arg0, s8*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 9;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
