#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9D3C(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x84);
    M2C_FIELD(temp_a1, u8*, 7) = (u8)(M2C_FIELD(temp_a1, u8*, 7) + 1);
    M2C_FIELD(arg0, s8*, 5) = 5;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
}
