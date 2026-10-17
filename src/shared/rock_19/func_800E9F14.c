#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_800EA1B0[];
extern u16 D_800EA1D0[][2];
extern u8 D_800EA1F0[];

#define SCR20 (*(s32**)0x1F800020)
#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_800E9F14(void* arg0) {
    s32* p;
    s8 idx;
    s32 off;

    F(u16, 0x40) = 0x1880;
    p = SCR20;
    idx = F(s8, 0x2);
    off = *p;
    {
        void* t = D_800EA1B0;
        F(u16, 0x42) = 0x7800;
        F(void*, 0x30) = t;
    }
    F(u8, 0x15) = 0;
    F(s8, 0x14) = -1;
    F(s32, 0x3C) = (s32)p + off;
    F(u16, 0xA) = D_800EA1D0[idx][0];
    F(u16, 0xE) = D_800EA1D0[idx][1];
    func_800179A4(arg0, D_800EA1F0[idx]);
    {
        // !FAKE: test value in the first return register
        register s32 t asm("$2") = F(u8, 0x2);
        if ((u32)(t - 6) < 2) {
            F(u16, 0x42) = 0x7804;
        }
    }
    F(u8, 0x16) = 3;
    F(u8, 0x4) = F(u8, 0x4) + 1;
    F(u8, 0x5) = F(u8, 0x2);
    if (F(s8, 0x5) >= 2) {
        F(u8, 0x3) = 1;
    }
}
#undef SCR20
#undef F
