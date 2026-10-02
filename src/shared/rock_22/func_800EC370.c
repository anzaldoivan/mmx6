#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8003D330();                          /* extern */

void func_800EC370(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002943C(0x3C, 3, 2);
        func_8003D330();
    }
}
