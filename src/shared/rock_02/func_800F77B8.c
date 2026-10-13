#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */

void func_800F77B8(void* arg0) {
    if (SPAD4C[0x8A] != 0x11) {
        M2C_FIELD(arg0, u8*, 5) = 0xE;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    {
        register s32 temp_b asm("$2");
        func_800179A4(arg0, 7);
        temp_b = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = temp_b + 1;
    }
}
