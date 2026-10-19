#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();

void func_800F2F78(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800179A4(arg0, 1);
        func_80016C48(2, (func_8002D2D4() & 1) | 0x24, arg0);
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, u16*, 0x7E) -= 1;
    }
}
