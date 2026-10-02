#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);   /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F34F4(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x65) {
        func_80029478(0x28, 4, 1);
        func_80012D9C(6);
        func_80016C48(0, 2, arg0);
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
