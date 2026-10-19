#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_8009B79C;

void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2) {
    s16 dx;
    s16 dy;
    s8 idx;

    idx = arg0->bg_offset;
    arg0->on_screen = 0;
    if (idx < 0) {
        dx = arg0->x_pos.i.hi;
        dy = arg0->y_pos.i.hi;
    } else {
        dx = arg0->x_pos.i.hi - D_800971F8[idx].x_pos.i.hi;
        dy = arg0->y_pos.i.hi - D_800971F8[idx].y_pos.i.hi;
    }
    if ((u16)(dx + arg1) < (u16)(D_8009B79C + arg1 + arg1) &&
        (u16)(dy + arg2) < (u16)(arg2 + 0xF0 + arg2)) {
        arg0->on_screen = 1;
    }
}
