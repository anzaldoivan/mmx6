#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F5EA0;
extern M2C_UNK D_800F5EA4;
extern M2C_UNK D_800F5EA8;
extern M2C_UNK D_800F5F6C;

void func_800EAC9C(void* arg0) {
    struct X4_PlayerObj* pl;
    u8 b;
    s32 x;
    s32 y;

    FX(arg0, u8, 0x5C) = 0x20;
    FX(arg0, u8, 0x60) = 6;
    FX(arg0, u8, 0x61) = 0;
    FX(arg0, void*, 0x58) = &D_8007433C;
    pl = &g_Player;
    b = FX(pl, u8, 0x14);
    x = FX(arg0, s32, 0x8);
    y = FX(arg0, s32, 0xC);
    FX(arg0, s32, 0x20) = 0;
    FX(arg0, s32, 0x24) = 0;
    FX(arg0, s32, 0x28) = 0;
    FX(arg0, s32, 0x2C) = 0;
    FX(arg0, u8, 0x67) = 0;
    FX(arg0, u8, 0x70) = 0;
    FX(arg0, u8, 0x14) = b;
    FX(arg0, s32, 0x18) = x;
    FX(arg0, s32, 0x1C) = y;
    if (FX(pl, s32, 0x8) < x) {
        FX(arg0, u8, 0x15) = 0;
    } else {
        FX(arg0, u8, 0x15) = 0x40;
    }
    FX(arg0, void*, 0x30) = &D_800F5F6C;
    FX(arg0, u8, 0x16) = 4;
    FX(arg0, void*, 0x68) = &D_800F5EA0;
    FX(arg0, void*, 0x54) = &D_800F5EA8;
    FX(arg0, void*, 0x50) = &D_800F5EA4;
    set_animation(arg0, 0);
    FX(arg0, s16, 0x7C) = 0;
    FX(arg0, u8, 0x4) = 1;
    FX(arg0, u8, 0x5) = 4;
    FX(arg0, u8, 0x6) = 0;
}
