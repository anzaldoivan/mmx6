#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_80074F1C;

void func_800F7DCC(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0xD);
    M2C_FIELD(arg0, u16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, u16*, 0x7E) = 0;
    M2C_FIELD(arg0, s32**, 0x58) = &D_80074F1C;
    M2C_FIELD(arg0, u8*, 0x8E) = 0;
    M2C_FIELD(arg0, u8*, 6)++;
}
