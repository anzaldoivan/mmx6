#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_800970B4;

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P80(p) (*(u8**)((u8*)(p) + 0x80))

void func_800EBAF0(u8* arg0) {
    u8* par;
    u8 d;

    par = P80(arg0);
    UH(arg0, 0x40) = UH(par, 0x40);
    W(arg0, 0x30) = W(par, 0x30);
    W(arg0, 0x3C) = W(par, 0x3C);
    UH(arg0, 0x42) = UH(par, 0x42);
    d = D_800970B4;
    UB(arg0, 0x16) = 4;
    UB(arg0, 0x67) = 0;
    B(arg0, 3) = 0;
    W(arg0, 0x68) = 0;
    W(arg0, 0x50) = 0;
    W(arg0, 0x54) = 0;
    W(arg0, 0x58) = 0;
    UB(arg0, 0x61) = 0;
    UB(arg0, 0x15) = 0;
    UB(arg0, 0x14) = d;
    UH(arg0, 0xA) = UH(arg0, 0xA) + UH(par, 0xA);
    UH(arg0, 0xE) = UH(arg0, 0xE) + UH(par, 0xE);
    W(arg0, 0x20) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x2C) = 0;
    UB(arg0, 0x5C) = 0;
    UB(arg0, 0x60) = 0;
    ((void (*)(void*, s32))func_800179A4)(arg0, 1);
    B(arg0, 5) = 0;
    B(arg0, 6) = 0;
    UB(arg0, 4) = UB(arg0, 4) + 1;
}
