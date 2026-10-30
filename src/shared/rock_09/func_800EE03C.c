#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s32 D_800F62B0;
extern s32 D_800F62D8;

void func_800EE03C(s8* self) {
    s32 a;
    s32 b;

    M2C_FIELD(self, s8*, 0x0) = 0x41;
    M2C_FIELD(self, s8*, 0x16) = 7;
    M2C_FIELD(self, s8*, 0x15) = 0;
    M2C_FIELD(self, u16*, 0x40) = D_80095098[func_8002A47C(0x8F)] >> 7;
    M2C_FIELD(self, u8**, 0x3C) = (u8*)SPAD20 + SPAD20[func_8002A47C(0x8F)];
    a = func_8002A47C(0x8F);
    b = func_8002A47C(0x8F);
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, void**, 0x30) = &D_800F62B0;
    M2C_FIELD(self, void**, 0x68) = &D_800F62D8;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, s8*, 0x75) = 0;
    ((void (*)(void*, s32))set_animation)(self, 0);
    M2C_FIELD(self, s8*, 0x4)++;
}
