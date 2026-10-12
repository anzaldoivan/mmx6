#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC();
s32 func_80031474(void*);
extern void (*D_800FCE10[])(void*);

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800F7BF0(void* self) {
    u8* p;
    s8 s;
    u16 v;

    p = G(u8*, 0x80);
    s = *(s8*)(p + 4);
    if (s != 1 || *(s8*)(p + 7) == 0) {
        G(s8, 4) = 7;
        G(s8, 3) = 0;
        return;
    }
    G(s32, 0x18) = G(s32, 0x8);
    G(s32, 0x1C) = G(s32, 0xC);
    func_80017A04(self);
    D_800FCE10[G(s8, 5)](self);
    G(u8, 0x88) = 0;
    if (func_80031474(self) != 0) {
        G(u8, 0x88) = s;
    }
    func_80030ECC(self);
    if (G(u8, 0x89) == s) {
        v = G(u16, 0x42) | 0x8000;
    } else {
        v = G(u16, 0x42) & 0x7FFF;
    }
    G(u16, 0x42) = v;
}
