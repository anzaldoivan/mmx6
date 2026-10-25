#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_80028DAC(struct X4_BackgroundObj* arg0) {
    s16 pos;
    s16 diff;
    s16 tmp;
    u16 cur;
    u16 ref;

    tmp = background_objects[0].x_pos.i.hi >> 2;
    pos = tmp + (s16)arg0->unk40;
    diff = pos - arg0->unk14.i.hi;
    arg0->x_pos.i.hi = pos;
    arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + (s16)arg0->unk42;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos - 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos + 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi - 0x10;
            }
        }
    }
    cur = arg0->y_pos.i.hi;
    ref = arg0->unk18.i.hi;
    diff = cur - ref;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur - 0x140;
            } else {
                arg0->y_pos.i.hi = ref + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur + 0x140;
            } else {
                arg0->y_pos.i.hi = ref - 0x10;
            }
        }
    }
}
