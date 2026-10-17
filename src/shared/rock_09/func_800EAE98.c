#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EB1E4(void* arg0);

void func_800EAE98(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 0x45);

    if (state == 1) {
        func_80016C48(2, 0x1A, arg0);
        func_800EB1E4(arg0);
    } else if (state == 2) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
