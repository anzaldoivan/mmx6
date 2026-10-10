#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

s32 func_800179A4(void*, s32);
void func_800EB284();
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern s32 D_800F5C28;
extern s32 D_800F5B98;
extern s32 D_800F5B9C;

void func_800EABCC(void* arg0) {
    s8 v;
    register s32 c asm("$5");
    u8 b;
    register s32 e asm("$2");

    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5C) = 6;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F5C28;
    b = D_800970B4;
    do {
        M2C_FIELD(arg0, u8*, 0x16) = 7;
    } while (0);
    {
        register void* q58 asm("$2") = &D_800743DC;
        M2C_FIELD(arg0, void**, 0x58) = q58;
    }
    {
        register void* q50 asm("$2") = &D_800F5B98;
        M2C_FIELD(arg0, void**, 0x50) = q50;
    }
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    e = M2C_FIELD(arg0, s32*, 0x8);
    c = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    {
        register void* q54 asm("$3") = &D_800F5B9C;
        M2C_FIELD(arg0, void**, 0x54) = q54;
    }
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, s32*, 0x18) = e;
    M2C_FIELD(arg0, s32*, 0x1C) = c;
    M2C_FIELD(SPAD, s16*, 0x80) = 0x1E;
    func_800EB284(arg0, c, b);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        func_800179A4(arg0, 0);
        v = 2;
    } else {
        func_800179A4(arg0, 3);
        v = 3;
    }
    M2C_FIELD(arg0, s8*, 5) = v;
    do {
        func_800EB284(arg0);
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 6) = 0;
    } while (0);
}
