#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800E9EF0(void) {
    D_800971F8[2].x_pos.i.hi = D_800971F8[1].x_pos.i.hi / 4;
}
