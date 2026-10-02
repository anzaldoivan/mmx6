#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECFD0(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x8C);
    M2C_FIELD(arg0, u8*, 0x98) = (u8)M2C_FIELD(temp_a1, u8*, 0x98);
    if ((s8)M2C_FIELD(temp_a1, u8*, 0x98) == 2) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    }
    M2C_FIELD(temp_a1, u8*, 0x98) = 0U;
}
