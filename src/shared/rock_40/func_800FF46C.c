#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FF46C(void* arg0) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, u8*, 3) = 0U;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a0, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 3) = (u8)M2C_FIELD(temp_a0, u8*, 3);
}
