#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFE48 (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern u8 D_800970B4;
extern s32 D_800FC29C;
extern s32 D_800FC2A0;
extern s32 D_800FC2A4;
extern s32 D_800FC2A8;
extern s32 D_800FC2AC;
extern s32 D_800FC2B0;
extern s32 D_800FC2B4;
extern s32 D_800FC2B8;
extern s32 D_800FC2BC;
extern s32 D_800FC2C0;
extern s32 D_800FC428;
extern void* D_800FCFF0;
extern void* D_800FCFF4;
extern void* D_800FCFF8;
extern void* D_800FCFFC;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EFE48(void* self) {
    s32 a;
    s32 b;
    u8 c;

    F(s8, 0x5C) = 6;
    F(s8, 0x61) = 0;
    c = D_800970B4;
    F(s8, 0x67) = 0;
    F(void*, 0x30) = &D_800FC428;
    F(u8, 0x16) = 6;
    F(void*, 0x54) = 0;
    F(s32, 0x50) = 0;
    F(s8, 0x70) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(s8, 0x99) = 1;
    F(s8, 0x8B) = 0;
    F(u8, 0x14) = c;
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    if (!(F(s8, 2) & 0xF0)) {
        F(void*, 0x68) = &D_800FC2AC;
        F(s8, 0x60) = 6;
        D_800FCFF0 = &D_800FC29C;
        D_800FCFF4 = &D_800FC2A0;
        D_800FCFF8 = &D_800FC2A8;
        D_800FCFFC = &D_800FC2A4;
    } else {
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
        a = func_8002A47C(F(s8, 1));
        b = func_8002A47C(F(s8, 1)) + 1;
        a = (a + 1) * 4;
        F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
        F(u8*, 0x3C) =
            (u8*)SPAD20_800EFE48 + SPAD20_800EFE48[func_8002A47C(F(s8, 1)) + 1];
        F(s8, 0x60) = 7;
        F(void*, 0x68) = &D_800FC2C0;
        D_800FCFF0 = &D_800FC2B0;
        D_800FCFF4 = &D_800FC2B4;
        D_800FCFF8 = &D_800FC2BC;
        D_800FCFFC = &D_800FC2B8;
    }
    func_800179A4(self, 0);
    {
        // !FAKE: depin: dropping it breaks the match (134/137)
        register s32 t asm("$2") = F(u8, 2) & 0xF;
        if (!t) {
            F(u8, 0x15) = 0;
        } else {
            F(u8, 0x15) = 0x40;
        }
    }
    F(s8, 4) = 1;
    F(s8, 5) = 3;
    F(s8, 6) = 0;
}
