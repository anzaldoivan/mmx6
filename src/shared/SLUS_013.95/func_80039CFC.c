#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039CFC(void* arg0) {
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    if (!(temp_v1 & 3)) {
        return 0;
    }
    if (temp_v1 & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0xF0);
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        if (M2C_FIELD(arg0, u8*, 0x89) & 2) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0xF0);
    }
    return 1;
}
