#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_801010B4(void* arg0) {
    void* temp_a1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    if ((M2C_FIELD(temp_a1, s8*, 5) == 0xA) &&
        (M2C_FIELD(temp_a1, s8*, 6) >= 9)) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
