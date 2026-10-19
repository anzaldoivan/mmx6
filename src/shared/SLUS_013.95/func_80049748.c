#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_80077BFC[][2];

void func_80049748(struct X4_BaseObj* arg0, struct X4_BaseObj* arg1) {
    s32 idx;
    u8 t;

    idx = arg1->unk2;
    if (idx == 0) {
        if (arg1->unk5 == 0x23) {
            idx = 2;
        }
    }
    if (arg1->unk5 == 0x1F) {
        idx = 3;
    }
    t = arg1->unk15;
    arg0->unk15 = t;
    if (t == 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + D_80077BFC[idx][0];
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - D_80077BFC[idx][0];
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + D_80077BFC[idx][1];
}
