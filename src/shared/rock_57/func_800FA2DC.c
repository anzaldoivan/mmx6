#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA2DC(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = D_800971F8[0].x_pos.u.hi + 0x10;
    D_800971F8[0].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 >= 0x120) {
        D_800971F8[0].x_pos.u.hi = 0x120;
        D_800971F8[2].unk3 = 0;
        arg0->x_pos.i.lo = 0x1FD;
        arg0->x_pos.i.hi = 5;
        arg0->unk1++;
    }
}
