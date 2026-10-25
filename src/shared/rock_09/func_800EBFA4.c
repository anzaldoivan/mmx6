#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800179A4(void*, s32);
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern struct X4_Unk_unk68 D_800F5F04;
extern M2C_UNK D_800F5F0C;
extern M2C_UNK D_800F5F8C;

void func_800EBFA4(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (78/89)
    register void* p743 asm("$2");
    M2C_FIELD(arg0, u8*, 0x0) = 0x41;
    M2C_FIELD(arg0, u8*, 0x5C) = 3;
    M2C_FIELD(arg0, u8*, 0x60) = 3;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    p743 = &D_800743DC;
    M2C_FIELD(arg0, void**, 0x58) = p743;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F5F8C;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F5F04;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F5F0C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x80) = 0;
    M2C_FIELD(arg0, s32*, 0x84) = 0;
    M2C_FIELD(arg0, s32*, 0x88) = 0;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, s32*, 0x90) = 0;
    M2C_FIELD(arg0, s32*, 0x94) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0x4)++;
    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 0:
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        M2C_FIELD(arg0, u8*, 5) = 2;
        break;
    case 1:
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = 5;
        M2C_FIELD(arg0, s32*, 0x88) = 1;
        break;
    case 4:
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, s32*, 0x88) = 1;
        break;
    default:
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = 6;
        M2C_FIELD(arg0, s32*, 0x88) = 1;
        break;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
}
