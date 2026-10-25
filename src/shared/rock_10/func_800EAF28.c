#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C32C();
s32 func_800ED06C(void* arg0);
extern u8 D_800FA900[];

void func_800EAF28(void* arg0) {
    void* c;
    s32 r;
    // !FAKE: depin: dropping it breaks the match (106/114)
    register s32 one asm("$3");

    r = func_800ED06C(arg0);
    one = 1;
    if (r == 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, u8*, 0x60) = one;
    M2C_FIELD(arg0, s16*, 0x8A) = 0xB6;
    M2C_FIELD(arg0, s16*, 0x92) = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s16*, 0x94) = M2C_FIELD(arg0, s16*, 0xE);
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = one;
    M2C_FIELD(arg0, s16*, 0x88) = 0;
    M2C_FIELD(arg0, s16*, 0x96) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8**, 0x50) = D_800FA900 + 0x169C;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 4) = one;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    M2C_FIELD(arg0, u8*, 3) = 0;
    c = func_8002C32C();
    if (c != 0) {
        M2C_FIELD(c, u8*, 0) = 0x41;
        M2C_FIELD(c, u8*, 1) = 0x4F;
        M2C_FIELD(c, u8*, 2) = 0;
        M2C_FIELD(c, void**, 0x7C) = arg0;
        M2C_FIELD(c, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(c, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(c, s16*, 8) = 0;
        M2C_FIELD(c, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(c, s16*, 0xC) = 0;
        M2C_FIELD(c, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(c, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(c, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(c, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
        M2C_FIELD(c, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(c, s32*, 0x84) = M2C_FIELD(arg0, s32*, 0x84);
        M2C_FIELD(arg0, void**, 0x8C) = c;
        M2C_FIELD(c, s16*, 0x8C) = M2C_FIELD(arg0, s16*, 0x90);
    }
    switch (M2C_FIELD(arg0, s32*, 0x84)) {
    case 0:
        M2C_FIELD(arg0, s32*, 0x20) = 0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        break;
    case 1:
        M2C_FIELD(arg0, s32*, 0x20) = 0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
        break;
    case 2:
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
        break;
    case 3:
        M2C_FIELD(arg0, s32*, 0x20) = -0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
        break;
    case 4:
        M2C_FIELD(arg0, s32*, 0x20) = -0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        break;
    case 5:
        M2C_FIELD(arg0, s32*, 0x20) = -0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = -0x100000;
        break;
    case 6:
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -0x100000;
        break;
    case 7:
        M2C_FIELD(arg0, s32*, 0x20) = 0x100000;
        M2C_FIELD(arg0, s32*, 0x24) = -0x100000;
        break;
    }
}
