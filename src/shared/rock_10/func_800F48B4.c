#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC();
s32 func_80031474(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074E7C;
extern s8 D_8009711A;
extern void (*D_800FCC80[])(void*);
extern s32 D_800FD000;

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800F48B4(void* self) {
    s32 r;
    u16 t;

    G(s32, 0x18) = G(s32, 0x8);
    G(s32, 0x1C) = G(s32, 0xC);
    ((M2C_UNK(*)())func_80017A04)();
    D_800FCC80[G(s8, 5)](self);
    if (G(s8, 5) != 8 && G(s8, 2) == 0) {
        D_800FD000++;
    }
    G(u8, 0x8D) = 0;
    r = func_80031474(self);
    if (r < 0) {
        D_8009711A = 1;
        G(s8, 4) = 2;
        G(s8, 5) = 0;
        return;
    }
    if (r > 0) {
        if (r != 0x7F) {
            G(void*, 0x58) = &D_8007433C;
            if ((u32)(r - 0x19) < 2) {
                G(s16, 0x88) = 2;
            } else {
                G(s16, 0x88) = 0x1E;
            }
            if (r == 5 || r == 0xE || r == 0x24) {
                G(void*, 0x58) = &D_8007433C;
                G(u8, 0x8E) = 1;
                G(s16, 0x88) = 0x50;
                G(s8, 5) = 9;
                G(s8, 6) = 0;
            }
        } else {
            G(u8, 0x8D) = 1;
        }
    }
    t = G(u16, 0x88);
    if (G(s16, 0x88) != 0) {
        G(s16, 0x88) = t - 1;
        if (t & 2) {
            G(u16, 0x42) = G(u16, 0x42) | 0x8000;
        } else {
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        }
        if (G(s16, 0x88) == 0) {
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
            if (G(u8, 0x8E) == 1) {
                G(void*, 0x58) = &D_8007433C;
                G(u8, 0x8E) = 0;
            } else {
                G(void*, 0x58) = &D_80074E7C;
            }
        }
    }
    func_80030ECC(self);
}

#undef G
