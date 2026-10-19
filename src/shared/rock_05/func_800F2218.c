#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern s32 D_800F4148;

void func_800F2218(void* arg0) {
    ((void (*)(void*))func_80017A04)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
        M2C_FIELD(arg0, s32**, 0x68) = &D_800F4148;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
