#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800299E8(struct X4_BackgroundObj* arg0) {
    s32 t;
    u16 y;

    arg0->x_pos.u.hi = D_800971F8[0].x_pos.u.hi;
    y = D_800971F8[0].y_pos.u.hi;
    t = (s16)y / 2 + y;
    arg0->y_pos.u.hi = arg0->unk42 + t;
}
