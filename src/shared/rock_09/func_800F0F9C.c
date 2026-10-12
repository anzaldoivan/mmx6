#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_800F0F9C(struct X4_MainObj* arg0) {
    s16 x;
    s32 p;
    s32 d;

    if (D_800970A0.x_pos.i.hi > arg0->x_pos.i.hi) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    if (arg0->unk7E >= 4) {
        arg0->unk6 = 9;
        return;
    }
    p = D_800970A0.x_pos.i.hi;
    x = arg0->x_pos.i.hi;
    d = p - x;
    if (d >= 0) {
        if (d >= 0x40) {
            goto far;
        }
        goto near;
    }
    if ((d = x - p) >= 0x40) {
    far:
        if (D_800970A0.x_pos.i.hi > arg0->x_pos.i.hi) {
            arg0->x_speed = 0x30000;
        } else {
            arg0->x_speed = -0x30000;
        }
        arg0->unk6 = 4;
        return;
    }
near:
    arg0->y_speed = 0x30000;
    arg0->unk6 = 6;
}

#undef D_800970A0
