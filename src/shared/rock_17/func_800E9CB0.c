#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800E9CB0(void* arg0) {
    D_800971F8[2].x_pos.val += 0xFFFAE148;
    D_800971F8[2].y_pos.val = 0;
    D_800971F8[2].unk4C = 1;
    if (D_800971F8[2].x_pos.i.hi <= 0) {
        D_800971F8[2].x_pos.i.hi = 0;
        *(s16*)((u8*)arg0 + 4) = 0xA;
        *((u8*)arg0 + 1) += 1;
    }
}
