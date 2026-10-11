#include "common.h"
#include "mmx6/x4.h"

void func_800312DC(struct X4_MainObj* arg0, struct X4_MainObj* arg1, s16* arg2,
                   s16* arg3) {
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    *arg2 = arg1->x_pos.i.hi;
    *arg3 = arg1->y_pos.i.hi;
    if (arg1->id == 0x3A) {
        if (arg1->unk15 != 0) {
            *arg2 -= arg1->terrain_box->unk0;
            return;
        }
        *arg2 += arg1->terrain_box->unk0;
        return;
    }
    if (arg0->unk15 != 0) {
        x0 = arg0->x_pos.i.hi - arg0->terrain_box->unk0;
    } else {
        x0 = arg0->x_pos.i.hi + arg0->terrain_box->unk0;
    }
    y0 = arg0->y_pos.i.hi + arg0->terrain_box->unk1;
    if (arg1->unk15 != 0) {
        x1 = arg1->x_pos.i.hi - arg1->terrain_box->unk0;
    } else {
        x1 = arg1->x_pos.i.hi + arg1->terrain_box->unk0;
    }
    y1 = arg1->y_pos.i.hi + arg1->terrain_box->unk1;
    *arg2 = (x0 + x1) / 2;
    *arg3 = (y0 + y1) / 2;
}
