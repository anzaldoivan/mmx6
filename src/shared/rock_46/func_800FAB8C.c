#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FAB8C(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        D_800971F8[2].x_pos.u.hi = 0;
        D_800971F8[2].y_pos.u.hi = 0x500;
        D_800971F8[2].unk4C = 1;
        ((s16*)arg0)[4] = 0x16;
        ((s16*)arg0)[5] = 1;
        ((u8*)arg0)[1]++;
    }
}
