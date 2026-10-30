#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F6AF8;

void func_800F269C(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 4);
    M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
    if (M2C_FIELD(arg0, s16*, 0xA) < (D_800F6AF8 + 0x700)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFFB0000;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
