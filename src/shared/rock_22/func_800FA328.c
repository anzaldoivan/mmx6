#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800FA328(void* arg0) {
    ((void (*)())func_80017A04)();
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 0) |= 0x10;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
