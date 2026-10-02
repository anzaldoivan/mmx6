#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                        /* extern */

void func_800F9628(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_s1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_s1, u16*, 0xE);
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        func_80016C48(2, 0x6B, arg0);
    }
    if ((M2C_FIELD(temp_s1, s32*, 4) & 0xFFFF00) == 0x900) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, s8*, 0x93) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
