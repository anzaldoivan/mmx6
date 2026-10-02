/* Adapted from sozud/mmx4 @29b62af src/main/background.c:func_80027AFC, AGPL-3.0; proven shared with X6 by exact signature 3108906f66dd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800295E8(struct X4_BackgroundObj* arg0) {
    s16 delta;

    delta = arg0->x_pos.i.hi - arg0->unk14.i.hi;
    if (delta >= 0) {
        if (delta >= arg0->unk48) {
            delta = arg0->unk48;
        }
        arg0->x_pos.i.hi = delta + arg0->unk14.i.hi;
    } else {
        if (delta < arg0->unk49) {
            delta = arg0->unk49;
        }
        arg0->x_pos.i.hi = delta + arg0->unk14.i.hi;
    }
}
