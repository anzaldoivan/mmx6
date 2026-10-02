#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8001750C(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);   /* extern */

void func_800F5B9C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        func_8001750C(2, 0x14);
        func_800179A4(arg0, 4);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x105D;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
