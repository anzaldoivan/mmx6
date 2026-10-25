#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009B79C;

s32 func_8002CB50(struct X4_BaseObj* arg0) {
    s16 dx;
    s16 dy;
    s8 idx;

    idx = arg0->bg_offset;
    arg0->on_screen = 0;
    if (idx < 0) {
        dx = arg0->x_pos.i.hi;
        dy = arg0->y_pos.i.hi;
    } else {
        dx = arg0->x_pos.i.hi - background_objects[idx].x_pos.i.hi;
        dy = arg0->y_pos.i.hi - background_objects[idx].y_pos.i.hi;
    }
    if ((u16)(dx + 0x20) < (u16)(D_8009B79C + 0x40) &&
        (u16)(dy + 0x20) < 0x130) {
        arg0->on_screen = 1;
    }
}
