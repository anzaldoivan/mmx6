#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern struct X4_PlayerObj g_Player;

void func_80040A04(struct X4_PlayerObj* arg0) {
    s32 ang;

    M2C_FIELD(arg0, s16*, 0x7C) = (random_byte() % 13) + 4;
    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        ang = ratan2(arg0->y_pos.i.hi - py, px - arg0->x_pos.i.hi);
    }
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->x_vel.val = rcos(ang) * 0x10;
    arg0->y_vel.val = rsin(ang) * 0x10;
    if (arg0->x_vel.val > 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    switch (random_byte() % 3) {
    case 0:
        break;
    case 1:
        arg0->x_vel.val = (arg0->x_vel.val * 3) / 2;
        arg0->y_vel.val = (arg0->y_vel.val * 3) / 2;
        break;
    case 2:
        arg0->x_vel.val = arg0->x_vel.val * 2;
        arg0->y_vel.val = arg0->y_vel.val * 2;
        break;
    }
    arg0->unk6++;
}

#undef M2C_FIELD
