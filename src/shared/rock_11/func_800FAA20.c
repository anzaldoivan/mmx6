#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097222;
extern s32 D_800FD484;
extern s32 D_800FD488;

void func_800FAA20(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FD484;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FD488;
    M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x120;
    if (!(M2C_FIELD(arg0, u8*, 2) & 0xF)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    }
    M2C_FIELD(arg0, s16*, 0x88) = 0xC;
    M2C_FIELD(arg0, s16*, 0x8A) = 4;
    M2C_FIELD(arg0, u8*, 6) += 1;
}
