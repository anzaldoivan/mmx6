#include "common.h"
#include "mmx6/x4.h"

extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800F0F9C(struct X4_MainObj* arg0) {
    s16 x;
    s32 p;
    s32 d;

    if (g_Player.x_pos.i.hi > arg0->x_pos.i.hi) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    if (arg0->unk7E >= 4) {
        arg0->unk6 = 9;
        return;
    }
    p = g_Player.x_pos.i.hi;
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
        if (g_Player.x_pos.i.hi > arg0->x_pos.i.hi) {
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

#undef g_Player
