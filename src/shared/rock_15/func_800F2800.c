#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F1DA8(void*, s32, s32);            /* extern */

void func_800F2800(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x47) == 0xC) {
        func_800F1DA8(arg0, 4, 2);
        func_800F1DA8(arg0, 5, 2);
        func_80016C48(2, 0x79, arg0);
        M2C_FIELD(arg0, s8*, 7) = 2;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
