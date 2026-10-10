#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074BFC;
extern s8 D_8009711A;
extern void (*D_800F7BE8[])(void*);
extern u32 D_800F7DE0;
extern s32 D_800F7DE4;
extern s32 D_800F7DE8;
extern s32 D_800F7E30;

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800EFB9C(void* self) {
    s32 r;
    u8 t;

    r = func_80031474(self);
    if (r < 0) {
        G(s8, 4) = 2;
        G(s8, 5) = 0;
        G(s8, 6) = 0;
        G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        D_800F7DE4 = 1;
        D_8009711A = 1;
        func_8002CCB0(self, 0x40, 0x40);
        return;
    }
    func_80030ECC(self);
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            G(u8, 0x84) = 2;
        } else {
            G(u8, 0x84) = 0x1E;
        }
        G(void*, 0x58) = &D_8007433C;
    }
    if ((r == 9 || r == 0x12 || r == 0x2D) && D_800F7E30 == 0) {
        D_800F7DE8 = 1;
        G(s8, 5) = 0xA;
        G(s8, 6) = 0;
    }
    t = G(u8, 0x84);
    if (t != 0) {
        G(u8, 0x84) = t + 0xFF;
        if (t & 2) {
            G(u16, 0x42) = G(u16, 0x42) | 0x8000;
        } else {
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        }
        if (G(u8, 0x84) == 0) {
            G(void*, 0x58) = &D_80074BFC;
            G(u16, 0x42) = G(u16, 0x42) & 0x7FFF;
        }
    }
    D_800F7BE8[G(s8, 5)](self);
    if (G(s8, 5) != 2) {
        D_800F7DE0++;
    }
}

#undef G
