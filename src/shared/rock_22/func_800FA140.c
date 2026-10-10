#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA140(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x8F) = 0U;
    if (M2C_FIELD(arg0, s16*, 0xA) >= 0x2009) {
        M2C_FIELD(arg0, u8*, 0x8F) = 1U;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) >= 0xC1) {
        M2C_FIELD(arg0, u8*, 0x8F) = (u8)(M2C_FIELD(arg0, u8*, 0x8F) + 2);
    }
}
