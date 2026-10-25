#include "common.h"
#include "mmx6/x4.h"

extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800F6BE8;

void func_800F1064(struct X4_MainObj* arg0) {
    s16 x;
    // !FAKE: depin: dropping it breaks the match (39/56)
    register s32 p asm("$6");
    s32 d;

    if (++arg0->unk7C == 0x3C) {
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
            if (arg0->x_pos.i.hi < D_800F6BE8) {
                arg0->unk15 = 0x40;
                arg0->x_speed = 0x40000;
            } else {
                arg0->unk15 = 0;
                arg0->x_speed = -0x40000;
            }
        } else {
        near:
            if (g_Player.x_pos.i.hi > arg0->x_pos.i.hi) {
                arg0->unk15 = 0x40;
            } else {
                arg0->unk15 = 0;
            }
        }
        arg0->y_speed = 0;
        arg0->gravity = 0x1000;
        arg0->unk6 = 8;
    }
}
#undef g_Player
