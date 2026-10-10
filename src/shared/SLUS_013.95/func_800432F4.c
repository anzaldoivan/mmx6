#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800432F4(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x50);
    if (M2C_FIELD(temp_a1, s8*, 7) != 0) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
        M2C_FIELD(arg0, u8*, 3) = (u8)M2C_FIELD(temp_a1, u8*, 3);
        M2C_FIELD(arg0, u16*, 0x42) = (u16)M2C_FIELD(temp_a1, u16*, 0x42);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
