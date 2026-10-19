#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_80029598(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = (D_800970AA - arg0->x_pos.i.hi) - arg0->unk30;
    if (delta < 0) {
        arg0->x_pos.i.hi = delta + arg0->x_pos.i.hi;
        return;
    }
    delta = (D_800970AA - arg0->x_pos.i.hi) - arg0->unk32;
    if (delta > 0) {
        arg0->x_pos.i.hi = delta + arg0->x_pos.i.hi;
    }
}
