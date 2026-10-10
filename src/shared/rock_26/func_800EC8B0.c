#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern s32 D_80075CDC;
extern s32 D_800EFB54;
extern s32 D_800EFAE0[];
extern s32 D_800EFAE8[];
extern s32 D_800EFAF0[];
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

void func_800EC8B0(void* arg0) {
    s16 v;

    FLD(arg0, u8, 0x5C) = 8;
    FLD(arg0, u8, 0x60) = 8;
    FLD(arg0, u8, 0x61) = 0;
    FLD(arg0, s32*, 0x58) = &D_80075CDC;
    FLD(arg0, u8, 0x14) = D_800970A0.bg_offset;
    FLD(arg0, s32, 0x18) = FLD(arg0, s32, 0x8);
    FLD(arg0, s32, 0x1C) = FLD(arg0, s32, 0xC);
    FLD(arg0, s32, 0x20) = 0;
    FLD(arg0, s32*, 0x30) = &D_800EFB54;
    FLD(arg0, s32, 0x24) = 0;
    FLD(arg0, s32, 0x28) = 0;
    FLD(arg0, s32, 0x2C) = 0;
    FLD(arg0, u8, 0x67) = 0;
    FLD(arg0, u8, 0x70) = 0;
    FLD(arg0, u8, 0x15) = 0;
    FLD(arg0, u8, 0x16) = 6;
    FLD(arg0, u8, 0x80) = func_8002D2D4() & 1;
    FLD(arg0, s32*, 0x68) = &D_800EFAE0[FLD(arg0, u8, 0x80)];
    FLD(arg0, u8, 0x81) = 0;
    FLD(arg0, s32*, 0x54) = &D_800EFAF0[FLD(arg0, u8, 0x80)];
    FLD(arg0, s32*, 0x50) = &D_800EFAE8[FLD(arg0, u8, 0x80)];
    switch (FLD(arg0, s8, 0x2)) {
    case 0:
        v = 0x78;
        goto set;
    case 1:
        v = 0xC;
    set:
        FLD(arg0, s16, 0x7C) = v;
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, u8, 0x3) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 2:
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, s16, 0x7C) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 3:
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        FLD(arg0, s16, 0x7C) = 0;
        FLD(arg0, s16, 0x7E) = 0;
        FLD(arg0, u8, 0x5) = 3;
        break;
    case 4:
        FLD(arg0, u8, 0x3) = 1;
        FLD(arg0, s32, 0x20) = 0xFFF80000;
        FLD(arg0, s32, 0x24) = 0xFFFC0000;
        FLD(arg0, s32, 0x54) = 0;
        FLD(arg0, s32, 0x50) = 0;
        ((void (*)(void*, s32))func_800179A4)(arg0, FLD(arg0, u8, 0x80));
        FLD(arg0, u8, 0x5) = 4;
        FLD(arg0, s32, 0x68) = 0;
        FLD(arg0, s16, 0x7C) = 0x32;
        break;
    case 5:
        FLD(arg0, u8, 0x3) = 1;
        FLD(arg0, s32, 0x20) = 0x80000;
        FLD(arg0, s32, 0x24) = 0xFFFC0000;
        ((void (*)(void*, s32))func_800179A4)(arg0, FLD(arg0, u8, 0x80));
        FLD(arg0, u8, 0x5) = 4;
        FLD(arg0, s32, 0x68) = 0;
        FLD(arg0, s16, 0x7C) = 0x32;
        break;
    case 6:
        FLD(arg0, u8, 0x3) = 1;
        FLD(arg0, s32, 0x24) = 0xFFF70000;
        ((void (*)(void*, s32))func_800179A4)(arg0, FLD(arg0, u8, 0x80) + 2);
        FLD(arg0, u8, 0x5) = 1;
        break;
    case 7:
        FLD(arg0, u8, 0x3) = 1;
        if (FLD(arg0, s16, 0xA) > D_800970A0.x_pos.i.hi) {
            FLD(arg0, s32, 0x20) = 0xFFFEE000;
            FLD(arg0, u8, 0x15) = 0;
        } else {
            FLD(arg0, s32, 0x20) = 0x12000;
            FLD(arg0, u8, 0x15) = 0x40;
        }
        FLD(arg0, s32, 0x24) = 0x21000;
        FLD(arg0, s32, 0x2C) = 0x1080;
        ((void (*)(void*, s32))func_800179A4)(arg0, FLD(arg0, u8, 0x80));
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x7C) = 0x14;
        break;
    }
    FLD(arg0, u8, 0x4) = 1;
    FLD(arg0, u8, 0x6) = 0;
    FLD(arg0, u8, 0x7) = 0;
}
