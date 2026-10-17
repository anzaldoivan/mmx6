#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F85C0(void* arg0) {
    s8 temp_v1;
    s8 var_v0;

    temp_v1 = M2C_FIELD(arg0, s8*, 7);
    if (temp_v1 == 1) {
        func_80016C48(2, 0x59, arg0);
        func_800179A4(arg0, 0x11);
        var_v0 = 6;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
    } else if (temp_v1 == 2) {
        var_v0 = 8;
    } else {
        return;
    }
    M2C_FIELD(arg0, s8*, 6) = var_v0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}
