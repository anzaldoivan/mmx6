#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA500(struct X4_BackgroundObj* arg0) {
    D_800971F8[0].x_pos.u.hi += 0x10;
    if (D_800971F8[0].x_pos.i.hi >= 0x120) {
        D_800971F8[0].x_pos.u.hi = 0x120;
        D_800971F8[2].unk3 = 0;
        arg0->x_pos.u.lo = 0x39;
        arg0->x_pos.u.hi = 7;
        arg0->unk1++;
    }
}
