#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA26C(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = D_800971F8[0].y_pos.u.hi + 0x10;
    D_800971F8[0].y_pos.u.hi = temp_v0;
    if ((s16)temp_v0 >= 0x1A0) {
        D_800971F8[0].y_pos.u.hi = 0x1A0;
        arg0->x_pos.i.lo = 0x143;
        arg0->x_pos.i.hi = 1;
        arg0->unk1++;
    }
}
