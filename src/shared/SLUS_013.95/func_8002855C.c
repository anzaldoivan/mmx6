#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_8002855C(struct X4_BackgroundObj* arg0) {
    s16 q;
    s16 q2;
    s16 x;
    s16 d;
    u16 t;
    u16 y;
    u16 t2;

    q2 = (D_800971F8[0].x_pos.i.hi * 3) / 4;
    x = q2 + (s16)arg0->unk40;
    arg0->x_pos.i.hi = x;
    q = (D_800971F8[0].y_pos.i.hi * 3) / 4;
    arg0->y_pos.i.hi = q + (s16)arg0->unk42;
    t = arg0->unk14.u.hi;
    d = x - t;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->x_pos.i.hi = x - 0x140;
            } else {
                arg0->x_pos.i.hi = t + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->x_pos.i.hi = x + 0x140;
            } else {
                arg0->x_pos.i.hi = t - 0x10;
            }
        }
    }
    y = arg0->y_pos.u.hi;
    t2 = arg0->unk18.u.hi;
    d = y - t2;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->y_pos.u.hi = y - 0x140;
                return;
            }
            arg0->y_pos.u.hi = t2 + 0x10;
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                arg0->y_pos.u.hi = y + 0x140;
                return;
            }
            arg0->y_pos.u.hi = t2 - 0x10;
        }
    }
}
