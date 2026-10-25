#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

s32 func_8002CAB4(struct X4_BaseObj* arg0) {
    s32 x;
    s16 dy;
    s32 ret;
    s8 idx;

    idx = arg0->bg_offset;
    if (idx < 0) {
        x = arg0->x_pos.i.hi;
        dy = arg0->y_pos.i.hi;
    } else {
        x = (s16)(arg0->x_pos.i.hi - background_objects[idx].x_pos.i.hi);
        dy = arg0->y_pos.i.hi - background_objects[idx].y_pos.i.hi;
    }
    x += 0x40;
    if ((u16)x < 0x1C0) {
        ret = 0;
        if ((u16)(dy + 0x40) < 0x170) {
            return ret;
        }
    }
    return 1;
}
