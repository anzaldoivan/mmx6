#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AE;

void func_80029658(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = (D_800970AE - arg0->y_pos.i.hi) - arg0->unk2C;
    if (delta < 0) {
        arg0->y_pos.i.hi = delta + arg0->y_pos.i.hi;
        return;
    }
    delta = (D_800970AE - arg0->y_pos.i.hi) - arg0->unk2E;
    if (delta > 0) {
        arg0->y_pos.i.hi = delta + arg0->y_pos.i.hi;
    }
}
