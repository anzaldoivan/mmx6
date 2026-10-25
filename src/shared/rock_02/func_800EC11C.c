#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern M2C_UNK D_800FADC4;
extern M2C_UNK D_800FADF8;
extern M2C_UNK D_800FAE00;

void func_800EC11C(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (96/103)
    register s32 t asm("$5") = D_800970B4;
    // !FAKE: depin: dropping it breaks the match (95/103)
    register void* q asm("$3") = &D_800FADF8;

    M2C_FIELD(arg0, void**, 0x30) = &D_800FADC4;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FAE00;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x54) = q;
    M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 5;
    M2C_FIELD(arg0, u8*, 0x60) = 3;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t;
    SPAD4C[0x81] = func_8002D2D4() & 3;
    SPAD4C[0x89] = 0;
    if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x67) = 1;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        func_800179A4(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 3;
    }
    if ((M2C_FIELD(arg0, u8*, 2) & 0xF) == 1) {
        M2C_FIELD(arg0, u8*, 0x4) = 3;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        func_800179A4(arg0, 1);
        SPAD4C[0x8A] = M2C_FIELD(arg0, u8*, 0x6);
        SPAD4C[0x8B] = M2C_FIELD(arg0, u8*, 0x7C);
        *(u16*)(SPAD4C + 0x8E) = M2C_FIELD(arg0, u16*, 0xE);
        *(s32*)(SPAD4C + 0x90) = M2C_FIELD(arg0, s32*, 0x24);
        *(s32*)(SPAD4C + 0x94) = M2C_FIELD(arg0, s32*, 0x2C);
        M2C_FIELD(arg0, u8*, 0x5) = 7;
    }
}
