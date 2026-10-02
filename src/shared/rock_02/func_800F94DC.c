#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002D2B0(s32);                     /* extern */
M2C_UNK func_8003D330();                        /* extern */

void func_800F94DC(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        func_80016C48(5, 0, arg0);
    } else if (temp_v1 == 2) {
        func_8002D2B0(arg0);
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < 0xC0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003D330();
        }
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}
