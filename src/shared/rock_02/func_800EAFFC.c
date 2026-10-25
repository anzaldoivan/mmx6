#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern M2C_UNK g_Player;
extern u8 D_800CCF38;
extern M2C_UNK D_800FAADC;
extern M2C_UNK D_800FAAE0;
extern M2C_UNK D_800FAAE4;
extern M2C_UNK D_800FAB24;

void func_800EAFFC(void* arg0) {
    s32 x;
    s32 y;
    u8 b;
    u8* pl;

    M2C_FIELD(arg0, u8*, 0x5C) = 0xC;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
    pl = (u8*)&g_Player;
    b = M2C_FIELD(pl, u8*, 0x14);
    x = M2C_FIELD(arg0, s32*, 8);
    y = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, s32*, 0x18) = x;
    M2C_FIELD(arg0, s32*, 0x1C) = y;
    if (M2C_FIELD(pl, s32*, 8) < x) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, void**, 0x30) = &D_800FAB24;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, void**, 0x68) = &D_800FAADC;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FAAE4;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FAAE0;
    func_800179A4(arg0, 0);
    {
        // !FAKE: depin: dropping it breaks the match (64/68)
        register s32 one asm("$2") = 1;
        M2C_FIELD(arg0, u8*, 5) = one;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 1;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 6) = 0;
    if (D_800CCF38 >= 2) {
        M2C_FIELD(arg0, u8*, 2) = 1;
    }
}
