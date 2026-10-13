#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F90FC (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s8 D_800CCEED;
extern s32 D_800FBB2C;

void func_800F90FC(void* arg0) {
    s32 a;
    s32 base;
    s32 c;

    if (M2C_FIELD(arg0, s8*, 0x2) == 0 && D_800CCEED == 2) {
        return;
    }
    M2C_FIELD(arg0, u16*, 0x40) = D_80095098[func_8002A47C(0x84)] >> 7;
    M2C_FIELD(arg0, u16*, 0x42) =
        ((func_8002A47C(0x84) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x84) + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(0x84);
    base = SPAD20_800F90FC;
    c = *(s32*)(a * 4 + base);
    M2C_FIELD(arg0, s32**, 0x30) = &D_800FBB2C;
    M2C_FIELD(arg0, u16*, 0xA) = 0x1750;
    M2C_FIELD(arg0, u16*, 0xE) = 0x194;
    M2C_FIELD(arg0, u8*, 0x16) = 3;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, s32*, 0x3C) = base + c;
    ((void (*)())func_80017A04)(arg0);
    M2C_FIELD(arg0, u8*, 0x3) = 1;
    M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        return;
    }
    M2C_FIELD(arg0, u16*, 0xA) += 0x14;
    ((void (*)(void*, s32))func_800179A4)(arg0, 1);
    M2C_FIELD(arg0, u8*, 0x5) = 5;
}

#undef SPAD20_800F90FC
