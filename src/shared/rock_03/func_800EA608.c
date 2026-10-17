#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EA608(void* arg0) {
    s8 t;

    t = M2C_FIELD(arg0, s8*, 0x2);
    if (t == 0) {
        func_800179A4(arg0, 8);
    } else if (t == 1) {
        func_800179A4(arg0, 0x15);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
