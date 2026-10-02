#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_801EB02C(void*);          /* extern */

void func_8003FE74(void* arg0, s32 arg1) {
    s8 var_v0;

    M2C_FIELD(arg0, s8*, 7) = 0;
    if (((M2C_FIELD(arg0, s32*, 4) & 0xFFFF00) == 0xB00) ||
        (M2C_FIELD(arg0, s8*, 5) == 0x2F)) {
        func_8003BA04(arg0, 0xBB);
        var_v0 = 2;
        goto block_6;
    }
    if (arg1 == 0) {
        func_8003BA04(arg0, 0xB7);
        M2C_FIELD(arg0, s8*, 7) = 0;
    } else {
        func_8003BA04(arg0, 0xB8);
        var_v0 = 1;
    block_6:
        M2C_FIELD(arg0, s8*, 7) = var_v0;
    }
    M2C_FIELD(arg0, s8*, 5) = 0x4C;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    func_801EB02C(arg0);
}
