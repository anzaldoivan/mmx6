#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
extern s32 D_80097420;

void func_800F9170(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    if (!(D_80097420 & 0x3F)) {
        func_80016C48(2, 0x69, arg0);
    }
}
