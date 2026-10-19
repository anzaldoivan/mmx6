#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF08;

#define TIMER(p) (*(s16*)&(p)->unk4)

void func_800FA384(struct X4_BackgroundObj* arg0) {
    s32 var_v0;
    s32 var_v1;
    s32 temp_v0;

    if (TIMER(arg0) != 0) {
        TIMER(arg0)--;
    }
    if (func_800EA480((s8*)arg0) != 0 && TIMER(arg0) == 0) {
        temp_v0 = D_800971F8[1].x_pos.u.hi - 0x10;
        D_800971F8[1].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            s32 c = D_800CCF08;
            do {
            } while (0);
            D_800971F8[1].x_pos.u.hi = 0;
            var_v0 = 0x98;
            if (c == 0) {
                var_v0 = 0x8E;
            }
            var_v1 = 1;
            arg0->x_pos.i.lo = var_v0;
            arg0->x_pos.i.hi = var_v1;
            do {
            } while (0);
            arg0->unk1++;
        }
    }
}

#undef TIMER
