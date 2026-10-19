#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern s8 D_800CCF08;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA4D0(u8* arg0) {
    s32 temp;

    if (func_800EA480((s8*)arg0) != 0) {
        if (D_800CCF08 != 0) {
            temp = (u16)D_800971F8[0].x_pos.i.hi + 0x10;
            D_800971F8[0].x_pos.i.hi = temp;
            if ((s16)temp >= 0x120) {
                D_800971F8[0].x_pos.i.hi = 0x120;
                D_800971F8[0].unk4C = 1;
                D_800971F8[1].x_pos.i.hi = 0x120;
                D_800971F8[1].y_pos.i.hi = 0x100;
                D_800971F8[1].unk4C = 1;
                D_800971F8[1].unk3 = 1;
                *(s16*)(arg0 + 8) = 0xA1;
                *(s16*)(arg0 + 0xA) = 2;
                arg0[1]++;
            }
        } else {
            arg0[1] = 9;
        }
    }
}
