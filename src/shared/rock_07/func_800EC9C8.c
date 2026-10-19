#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */

void func_800EC9C8(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 0x7) == 4) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x47, arg0);
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
