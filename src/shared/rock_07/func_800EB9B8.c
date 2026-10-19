#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800EB9B8(u8* arg0) {
    s32 t;

    t = D_800971F8[1].y_pos.u.hi + 8;
    D_800971F8[1].y_pos.u.hi = t;
    if ((s16)t >= 0x368) {
        D_800971F8[1].y_pos.u.hi = 0x368;
        *(s16*)(arg0 + 0x7E) = 3;
        arg0[6] = arg0[6] + 1;
    }
}
