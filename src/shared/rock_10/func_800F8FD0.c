#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F8FD0(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80016C48(2, 0x52, arg0);
        func_800179A4(arg0, 6);
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
