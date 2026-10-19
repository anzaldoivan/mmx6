#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEED;

void func_800E9E88(struct X4_AnimatedObj* arg0) {
    if (D_800CCEED != 0) {
        D_800971F8[1].unk42 = 0x140;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].unk4 = 5;
        D_800971F8[2].x_pos.i.hi = D_800971F8[1].x_pos.i.hi / 4;
        D_800971F8[2].y_pos.i.hi = 0x1C0;
        D_800971F8[2].unk4C = 1;
        arg0->state++;
    }
}
