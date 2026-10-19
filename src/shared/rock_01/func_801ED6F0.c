#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s32 D_80097420;
extern s32 D_801EE2D4[];
extern s32 D_801EE414[];
extern s32 D_801EE580[];
extern u8 D_801EE68C[][4];

#define ED6F0_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define ED6F0_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define ED6F0_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define ED6F0_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define ED6F0_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801ED6F0(u8* self, u8* parent) {
    s8 v = ED6F0_S8(self, 0x45);

    ED6F0_S32(self, 0x8) = ED6F0_S32(parent, 0x8);
    ED6F0_S32(self, 0xC) = ED6F0_S32(parent, 0xC);
    ED6F0_U8(self, 0x15) = ED6F0_U8(parent, 0x15);
    if (v == 0) {
        ED6F0_PTR(self, 0x50) = 0;
    } else if ((ED6F0_S32(parent, 0xEC) & 0x800000) &&
               !(ED6F0_S8(self, 0) & 0x80) &&
               D_801EE68C[ED6F0_S8(self, 1) - 0x18][2] != 0) {
        ED6F0_PTR(self, 0x50) = &D_801EE580[v];
    } else {
        ED6F0_PTR(self, 0x50) = &D_801EE414[ED6F0_S8(self, 0x45)];
    }
    if (ED6F0_S8(self, 1) == 0x24) {
        if (ED6F0_S8(self, 0x45) >= 0x4B && ED6F0_S8(self, 0x45) < 0x50) {
            ED6F0_PTR(self, 0x68) = &D_801EE2D4[ED6F0_S8(self, 0x45)];
        } else {
            ED6F0_PTR(self, 0x68) = 0;
        }
    }
    if (ED6F0_S8(self, 1) == 0x18 || ED6F0_S8(self, 1) == 0x19 ||
        ED6F0_S8(self, 1) == 0x25 || ED6F0_S8(self, 1) == 0x26 ||
        ED6F0_S8(self, 1) == 0x27 || ED6F0_S8(self, 1) == 0x28 ||
        ED6F0_S8(self, 1) == 0x29) {
        ED6F0_U8(self, 0x64) = ED6F0_U8(self, 2) + 1;
    } else if (ED6F0_S8(self, 1) == 0x1A || !(D_80097420 & 3)) {
        ED6F0_U8(self, 0x64) = ED6F0_S8(self, 0x45);
    }
    if (ED6F0_S8(self, 1) == 0x23 || ED6F0_S8(self, 1) == 0x24) {
        if (ED6F0_S32(self, 0x90) != 0) {
            ED6F0_S32(self, 0x90)--;
            ED6F0_PTR(self, 0x50) = 0;
        }
        if (ED6F0_S8(self, 0x98) != 0) {
            ED6F0_S8(self, 0x98) = 0;
            ED6F0_S32(self, 0x90) = 2;
            ED6F0_PTR(self, 0x50) = 0;
            ED6F0_U32(self, 0x8C)++;
        }
        if (ED6F0_U32(self, 0x8C) >= 4) {
            ED6F0_PTR(self, 0x50) = 0;
        }
    }
    if (ED6F0_S8(self, 1) == 0x1A && ED6F0_S8(parent, 5) == 0x37) {
        ED6F0_PTR(self, 0x50) = 0;
    }
    func_8002CCB0(self, 0x80, 0x80);
}

#undef ED6F0_S8
#undef ED6F0_U8
#undef ED6F0_S32
#undef ED6F0_U32
#undef ED6F0_PTR
