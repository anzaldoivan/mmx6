#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern s32 D_80077A80;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_801F37CC;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801ED058(u8* arg0) {
    u8* sc;
    u8* sc2;
    u32 r;
    s32 t;
    s32 x;

    B(arg0, 0) = 1;
    B(arg0, 3) = 1;
    B(arg0, 0x64) = 1;
    W(arg0, 0x50) = (s32)&D_801F37CC;
    sc2 = SCRATCH_14;
    W(arg0, 0x38) = (s32)(sc2 + W(sc2, 0x3C));
    sc = SCRATCH_1C;
    t = W(sc, 0x18);
    W(arg0, 0x30) = (s32)&D_80077A80;
    H(arg0, 0x40) = 0x540;
    H(arg0, 0x42) = 0x7802;
    B(arg0, 0x16) = 0;
    B(arg0, 0x15) = 0;
    W(arg0, 0x20) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x3C) = (s32)(sc + t);
    if (SB(arg0, 2) == 0) {
        W(arg0, 0x24) = 0xFFF40000;
        H(arg0, 0xE) = D_800971F8[0].y_pos.i.hi - 0x20;
        func_800179A4(arg0, 2);
    } else {
        W(arg0, 0x24) = 0xC0000;
        H(arg0, 0xE) = D_800971F8[0].y_pos.i.hi + 0x110;
        func_800179A4(arg0, 1);
    }
    W(arg0, 0x2C) = 0;
    r = func_8002D2D4();
    x = D_800971F8[0].x_pos.u.hi + 8;
    B(arg0, 5) = 0;
    B(arg0, 4)++;
    H(arg0, 0xA) = (u8)(r % 20) * 16 + x;
}
