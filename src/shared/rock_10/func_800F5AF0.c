#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_BackgroundObj D_800971F8[3];

#define ABS_LT7(d) (((d) < 0 ? -(d) : (d)) < 7)

void func_800F5AF0(struct X4_AnimatedObj* arg0) {
    s16 ox;
    s16 oy;
    s32 angle;
    s32 v;
    s32 t;
    s32 d;

    switch (arg0->unk2) {
    case 0x30:
        ox = 0x120;
        oy = 0x20;
        break;
    case 0x31:
        ox = 0x20;
        oy = 0x20;
        break;
    case 0x32:
        ox = 0x20;
        oy = 0x90;
        break;
    case 0x33:
        ox = 0x120;
        oy = 0x90;
        break;
    }
    angle = func_80065B74(arg0->y_pos.i.hi - (D_800971F8[0].y_pos.i.hi + oy),
                          (D_800971F8[0].x_pos.i.hi + ox) - arg0->x_pos.i.hi);
    do {
        v = func_80065A14(angle);
        t = v * 16;
        arg0->x_vel.val = (v * 32 + t) * 2;
        v = func_80065944(angle);
        t = v * 16;
        arg0->y_vel.val = (v * 32 + t) * 2;
    } while (0);
    v = arg0->x_vel.val;
    if (v >= 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    ((void (*)(struct X4_AnimatedObj*))func_8002D2B0)(arg0);
    d = arg0->x_pos.i.hi - D_800971F8[0].x_pos.i.hi;
    if (ABS_LT7(ox - d)) {
        if (ABS_LT7(oy - (arg0->y_pos.i.hi - D_800971F8[0].y_pos.i.hi))) {
            arg0->x_pos.i.hi = D_800971F8[0].x_pos.i.hi + ox;
            arg0->y_pos.i.hi = D_800971F8[0].y_pos.i.hi + oy;
            switch (arg0->unk2) {
            case 0x30:
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x23);
                arg0->unk15 = 0;
                break;
            case 0x31:
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x23);
                arg0->unk15 = 0x40;
                break;
            case 0x32:
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x24);
                arg0->unk15 = 0x40;
                break;
            case 0x33:
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x24);
                arg0->unk15 = 0;
                break;
            }
            arg0->unk5++;
        }
    }
}
