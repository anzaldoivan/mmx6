#include "common.h"
#include "mmx6/x4.h"
extern s8 D_8007673C[];
extern s8 D_8007693C[];
extern s16 D_801F3894[][2];
extern u8 D_801F49F4[];

s32 func_801EE34C(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1,
                  s32 arg2) {
    s32 idx;
    s16 dx;
    s16 dy;
    s8 i;

    i = arg2;
    idx = ((u8*)arg1)[0x47] * 2;
    if (D_801F49F4[arg1->unk17] == 0) {
        dx = D_8007673C[idx];
        dy = D_8007673C[idx + 1];
    } else {
        dx = D_8007693C[idx];
        dy = D_8007693C[idx + 1];
    }
    if (arg0->unk15 != 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - dx;
        arg0->x_pos.i.hi -= D_801F3894[i][0];
    } else {
        arg0->x_pos.i.hi = dx + arg1->x_pos.i.hi;
        arg0->x_pos.i.hi += D_801F3894[i][0];
    }
    arg0->y_pos.i.hi = dy + arg1->y_pos.i.hi;
    arg0->y_pos.i.hi += D_801F3894[i][1];
}
