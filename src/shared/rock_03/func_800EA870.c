#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */

void func_800EA870(void* arg0) {
    s8 temp_v1;

    func_80016C48(2, 6, arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    if (temp_v1 == 0) {
        func_800179A4(arg0, 0x16);
    } else if (temp_v1 == 1) {
        func_800179A4(arg0, 0x17);
    }
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
