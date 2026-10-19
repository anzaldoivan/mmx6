#include "common.h"
#include "mmx6/x4.h"

void func_800E9F7C(void);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_80097424;

void func_800FA1C0(struct X4_BackgroundObj* arg0) {
    if (D_80097424 == 0) {
        D_800971F8[2].unk3 = 1;
        D_800971F8[1].unk3 = 1;
        D_800971F8[1].x_pos.i.hi = 0x120;
        func_800E9F7C();
        {
            s32 t = arg0->unk1;
            s32 c;
            c = 0x1F5;
            arg0->x_pos.i.lo = c;
            c = 7;
            arg0->x_pos.i.hi = c;
            arg0->unk1 = t + 1;
        }
    }
}
