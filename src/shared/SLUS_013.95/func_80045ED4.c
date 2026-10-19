#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_80076194[][2];

void func_80045ED4(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1) {
    if (arg1->unk15 != 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][1];
}
