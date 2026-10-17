#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800FDE30;

#define PARENT (*(u8**)((u8*)&D_800FDE30 + 0x468))
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800FC02C(void* arg0) {
    u8* p;
    u8* q;
    u8 t;
    s32 x;

    p = PARENT;
    H(arg0, 0x40) = H(p, 0x40);
    H(arg0, 0x42) = H(p, 0x42) & 0x7FFF;
    W(arg0, 0x30) = W(p, 0x30);
    x = W(p, 0x3C);
    B(arg0, 0x14) = 0;
    B(arg0, 0x16) = 6;
    q = PARENT;
    W(arg0, 0x3C) = x;
    t = B(q, 0x15);
    B(arg0, 0x67) = 0;
    B(arg0, 3) = 0;
    W(arg0, 0x68) = 0;
    W(arg0, 0x50) = 0;
    W(arg0, 0x54) = 0;
    W(arg0, 0x58) = 0;
    B(arg0, 0x15) = t;
    if (t == 0) {
        H(arg0, 0xA) = H(PARENT, 0xA) - 0xD;
    } else {
        H(arg0, 0xA) = H(PARENT, 0xA) + 0xD;
    }
    H(arg0, 0xE) = H(PARENT, 0xE) - 0x32;
    W(arg0, 0x20) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x2C) = 0;
    B(arg0, 0x5C) = 0;
    B(arg0, 0x60) = 0;
    W(arg0, 0x8C) = 0;
    func_800179A4(arg0, 0x10);
    t = B(arg0, 4);
    B(arg0, 5) = 0;
    B(arg0, 4) = t + 1;
}
#undef PARENT
#undef B
#undef H
#undef W
