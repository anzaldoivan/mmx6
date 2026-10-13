#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80029F38();
M2C_UNK func_8002C9B0();
extern s8 D_8008EAB0;
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEED;

void func_800EDBB8(s32 arg0) {
    u16 oy;
    u16 ox;

    if (D_800970A0.unk5 == 0x14) {
        D_8008EAB0 = 1;
        oy = D_800971F8[0].y_pos.i.hi;
        ox = D_800971F8[0].x_pos.i.hi;
        D_800971F8[1].unk4 = 5;
        D_800971F8[0].y_pos.i.hi = 0x3B0;
        D_800971F8[1].y_pos.i.hi = 0x3C0;
        D_800971F8[2].y_pos.i.hi = 0x3B0;
        D_800971F8[0].unk24 = 0x17C0;
        D_800971F8[0].unk1C = 0x17C0;
        D_800971F8[1].x_pos.i.hi = 0;
        D_800971F8[0].unk4C = 1;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].unk4C = 1;
        D_800971F8[0].unk26 = 0;
        D_800971F8[0].unk1E = 0;
        D_800971F8[0].unk2A = 0x3B0;
        D_800971F8[0].unk22 = 0x3B0;
        D_800971F8[0].unk28 = 0x3B0;
        D_800971F8[0].unk20 = 0x3B0;
        D_800CCEED = 1;
        D_800971F8[0].x_pos.i.hi = ox - 0x1240;
        D_800971F8[2].x_pos.i.hi = D_800971F8[0].x_pos.i.hi / 2;
        {
            s16 d = D_800970A0.x_pos.i.hi - ox;
            D_800970A0.x_pos.i.hi = d + D_800971F8[0].x_pos.i.hi;
        }
        {
            s16 d = D_800970A0.y_pos.i.hi - oy;
            D_800970A0.y_pos.i.hi = d + D_800971F8[0].y_pos.i.hi;
        }
        {
            s16 d = D_800970A0.unk18.i.hi - ox;
            D_800970A0.unk18.i.hi = d + D_800971F8[0].x_pos.i.hi;
        }
        {
            s16 d = D_800970A0.unk1C.i.hi - oy;
            D_800970A0.unk1C.i.hi = d + D_800971F8[0].y_pos.i.hi;
        }
        func_80029F38(D_800971F8[0].x_pos.i.hi - 0x30,
                      D_800971F8[0].x_pos.i.hi + 0x170, 0x380, 0x4D0, 0);
        func_8002C9B0(arg0);
    }
}
