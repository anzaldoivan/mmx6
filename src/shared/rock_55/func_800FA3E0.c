#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FA3E0(u8* arg0) {
    if (!(D_80097420 & 1)) {
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
    }
    if ((u16)D_800CF854 >= 0x1F) {
        D_800971F8[1].x_pos.i.hi = 0;
        D_800971F8[1].y_pos.i.hi = 0x100;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].x_pos.i.hi = 0;
        D_800971F8[2].y_pos.i.hi = 0x100;
        D_800971F8[2].unk4C = 1;
        arg0[1]++;
    }
}
