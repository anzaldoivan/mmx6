#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;

void func_800EC460(struct X4_PlayerObj* arg0) {
    if (arg0->x_pos.i.hi < D_800970A0.x_pos.i.hi) {
        arg0->unk7 = 6;
    } else if (arg0->y_pos.i.hi < D_800970A0.y_pos.i.hi) {
        arg0->unk7 = 7;
    } else {
        arg0->unk7 = 5;
    }
    arg0->unk6++;
}
