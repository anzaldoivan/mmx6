#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA028(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x3C) += 0x20000;
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (M2C_FIELD(arg0, s16*, 0x3E) >= 0xF0) {
        M2C_FIELD(arg0, s16*, 0x3E) = 0xF0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    M2C_FIELD(arg0, s16*, 0x16) =
        M2C_FIELD(arg0, s16*, 0x42) - M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x1A) = M2C_FIELD(arg0, s16*, 0x46);
    M2C_FIELD(arg0, s16*, 0x1E) =
        M2C_FIELD(arg0, s16*, 0x42) + M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x22) = M2C_FIELD(arg0, s16*, 0x46);
    M2C_FIELD(arg0, s16*, 0x26) =
        M2C_FIELD(arg0, s16*, 0x3A) + M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x2A) = M2C_FIELD(arg0, s16*, 0x3E);
    M2C_FIELD(arg0, s16*, 0x2E) =
        M2C_FIELD(arg0, s16*, 0x3A) - M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x32) = M2C_FIELD(arg0, s16*, 0x3E);
}
