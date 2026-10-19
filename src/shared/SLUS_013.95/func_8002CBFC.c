#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2) {
    s8 bg;
    s16 x;
    s16 y;

    bg = arg0->bg_offset;
    if (bg < 0) {
        x = arg0->x_pos.i.hi;
        y = arg0->y_pos.i.hi;
    } else {
        x = arg0->x_pos.i.hi - D_800971F8[bg].x_pos.i.hi;
        y = arg0->y_pos.i.hi - D_800971F8[bg].y_pos.i.hi;
    }
    if ((u16)(x + arg1) < (u16)(arg1 * 2 + 0x140) &&
        (u16)(y + arg2) < (u16)(arg2 * 2 + 0xF0)) {
        return 0;
    }
    return 1;
}
