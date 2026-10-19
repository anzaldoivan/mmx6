#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800EA500(u8* arg0) {
    extern s8 D_80097420[];
    s8* e = D_80097420;

    if (e[4] == 0) {
        if ((u8)e[7] == 2) {
            arg0[1]++;
            return;
        }
        D_800971F8[0].x_pos.i.hi = 0;
        D_800971F8[0].y_pos.i.hi = 0;
        D_800971F8[0].unk4C = 1;
        D_800971F8[0].unk3 = 1;
        arg0[0] = 6;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}
