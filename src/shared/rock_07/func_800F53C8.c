#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800F53C8(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80016C48(2, 0x25, arg0);
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
