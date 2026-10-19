#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF08;

void func_800FA14C(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        if (D_800CCF08 == 0) {
            D_800971F8[2].unk3 = 1;
            D_800971F8[2].x_pos.u.hi -= 0x10;
            if ((s16)D_800971F8[2].x_pos.u.hi <= 0) {
                D_800971F8[2].x_pos.u.hi = 0;
                arg0->x_pos.u.lo = 0x93;
                arg0->x_pos.u.hi = 5;
                arg0->unk1++;
            }
        } else {
            D_8008EAB0 = 1;
            D_800971F8[2].y_pos.u.hi = 0x200;
            D_800971F8[0].y_pos.u.hi = 0x200;
            D_800971F8[2].unk3 = 1;
            D_800971F8[2].x_pos.u.hi = 0;
            D_800971F8[2].unk4C = 1;
            D_800971F8[1].unk3 = 0;
            D_800971F8[0].x_pos.u.hi = 0;
            D_800971F8[0].unk4C = 1;
            D_800971F8[0].unk3 = 1;
            arg0->x_pos.u.lo = 0xA0;
            arg0->x_pos.u.hi = 1;
            func_80016C48(0, 3, 0);
            arg0->unk1++;
        }
    }
}
