#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA4AC(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x78) {
        D_800971F8[0].unk3 = 1;
        D_800971F8[0].x_pos.u.hi = 0;
        D_800971F8[0].y_pos.u.hi = 0x100;
        D_800971F8[0].unk4C = 1;
        arg0[1]++;
        return;
    }
    (*(s16*)(arg0 + 4))++;
}
