#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA88C(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_800971F8[1].x_pos.u.hi -= 0x10;
        if ((s16)D_800971F8[1].x_pos.u.hi <= 0) {
            D_800971F8[1].x_pos.u.hi = 0;
            arg0->x_pos.u.lo = 0x128;
            arg0->x_pos.u.hi = 0x19;
            arg0->unk1++;
        }
    }
}
