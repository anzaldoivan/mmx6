#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80040498();
extern s32 D_80090C98;
extern u8 D_800C4560;

void func_800F4BEC(void* arg0) {
    if (func_80040498() == 0) {
        D_80090C98 = 0xFF;
        D_800C4560 |= 1;
        M2C_FIELD(arg0, s16*, 0xA) -= 6;
        M2C_FIELD(arg0, s16*, 0xE) += 0x18;
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 3;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
