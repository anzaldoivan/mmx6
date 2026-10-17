#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800F34FC[][4];
extern u16 D_800F3504[][8][2];
extern u16 D_800F35EC;

void func_800F089C() {
    u16 buf[4];
    s32 i;

    i = 0;
    D_800F35EC &= 7;
    do {
        buf[0] = D_800F3504[i][(s16)D_800F35EC][0];
        buf[1] = D_800F3504[i][(s16)D_800F35EC][1];
        buf[2] = D_800F34FC[i][2];
        buf[3] = D_800F34FC[i][3];
        func_80027BA0(0, D_800F34FC[i][0], D_800F34FC[i][1], (u8*)buf);
        i++;
    } while (i < 1);
    D_800971F8[0].unk4C = 1;
}
