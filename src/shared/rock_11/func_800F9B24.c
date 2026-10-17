#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F9B24(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x7) == 0) {
        ((void (*)(M2C_UNK, M2C_UNK, void*))func_80016C48)(2, 0x43, arg0);
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x17);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
