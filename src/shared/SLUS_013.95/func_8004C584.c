#include "common.h"

void func_800328B0();

#define W(o) (*(s32*)((u8*)arg0 + (o)))
#define B(o) (*(u8*)((u8*)arg0 + (o)))
#define SB(o) (*(s8*)((u8*)arg0 + (o)))

void func_8004C584(void* arg0) {
    if (++B(0x3A) == 0) {
        B(0x3A) = 0xFE;
    }
    W(0x14) += W(0x3C);
    W(0x18) += W(0x40);
    W(0x24) += W(0x44);
    W(0x28) += W(0x48);
    W(0x1C) = W(0x14) + 0x10000;
    W(0x20) = W(0x18) + 0x10000;
    W(0x2C) = W(0x24) - 0x10000;
    W(0x30) = W(0x28) - 0x10000;
    W(0x3C) += W(0x4C);
    W(0x40) += W(0x50);
    W(0x44) += W(0x54);
    W(0x48) += W(0x58);
    if (B(0x39) != 0) {
        B(0x39)--;
        return;
    }
    func_800328B0(arg0);
    if (SB(0x3) == 0 && B(0x3A) >= 0x3D) {
        B(0x4)++;
    }
}

#undef W
#undef B
#undef SB
