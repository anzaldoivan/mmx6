#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA600(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = D_800971F8[2].x_pos.u.hi - 0x10;
        D_800971F8[2].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            D_800971F8[2].x_pos.u.hi = 0;
            arg0->x_pos.i.lo = 0xA9;
            arg0->x_pos.i.hi = 4;
            D_800971F8[1].x_pos.u.hi = 0x120;
            D_800971F8[1].y_pos.u.hi = 0x400;
            D_800971F8[1].unk4C = 1;
            D_800971F8[1].unk3 = 1;
            arg0->unk1++;
        }
    }
}
