#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA4A8(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_800971F8[0].unk3 = 1;
        D_800971F8[0].x_pos.i.hi = 0;
        D_800971F8[0].y_pos.i.hi = 0x200;
        D_800971F8[0].unk4C = 1;
        arg0[1]++;
    }
}
