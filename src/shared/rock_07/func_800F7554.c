#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F7554(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x8C);
    if (M2C_FIELD(temp_a1, s8*, 0x4) != 3) {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x3) = M2C_FIELD(temp_a1, u8*, 0x3);
    if (M2C_FIELD(temp_a1, u16*, 0x42) & 0x8000) {
        M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
    } else {
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(temp_a1, u8*, 0x7) = 0;
    }
}
