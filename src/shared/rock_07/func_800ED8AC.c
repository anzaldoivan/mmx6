#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800F88E8[][4];
extern u16 D_800F8988[][8][2];
extern u16 D_800F985C;

void func_800ED8AC(void) {
    u16 buf[4];
    s32 i;

    i = 0;
    D_800F985C &= 7;
    do {
        buf[0] = D_800F8988[i][(s16)D_800F985C][0];
        buf[1] = D_800F8988[i][(s16)D_800F985C][1];
        buf[2] = D_800F88E8[i][2];
        buf[3] = D_800F88E8[i][3];
        ((void (*)(s32, s32, s32, u8*))func_80027BA0)(
            0, D_800F88E8[i][0], D_800F88E8[i][1], (u8*)buf);
        i++;
    } while (i < 20);
    D_800971F8[0].unk4C = 1;
}
