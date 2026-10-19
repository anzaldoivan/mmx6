#include "common.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800970B4;
extern s32 D_800FC948;
extern s32 D_800FC950;
extern s32 D_800FCE98;

void func_800FA920(void* arg0) {
    void* temp_a1;
    s32 b;
    s32 one;
    s32* p54;
    // !FAKE: regalloc
    register s32* p68 asm("$3");

    F(arg0, s32**, 0x30) = &D_800FCE98;
    one = 1;
    p54 = &D_800FC950;
    p68 = &D_800FC948;
    b = D_800970B4;
    temp_a1 = F(arg0, void**, 0x7C);
    F(arg0, u8*, 0x4) = one;
    F(arg0, u8*, 0x75) = one;
    F(arg0, s32**, 0x54) = p54;
    F(arg0, u8*, 0x62) = 0;
    F(arg0, u8*, 0x61) = 0;
    F(arg0, u8*, 0x3) = 0;
    F(arg0, u8*, 0x5) = 0;
    F(arg0, u8*, 0x6) = 0;
    F(arg0, s32**, 0x68) = p68;
    F(arg0, u8*, 0x5C) = 0;
    F(arg0, u8*, 0x60) = 6;
    F(arg0, u8*, 0x14) = b;
    F(arg0, s32*, 0x8) = F(temp_a1, s32*, 0x8);
    F(arg0, s32*, 0xC) = F(temp_a1, s32*, 0xC);
}
