#include "common.h"
#include "mmx6/x4.h"

void func_80032C88(void* arg0, void* arg1) {
    struct X4_AnimatedObj* a = arg0;
    struct X4_AnimatedObj* b = arg1;
    s16 d1;
    s16 d2;

    if (a->x_pos.i.hi != a->unk18.i.hi) {
        d1 = b->x_pos.i.hi - b->unk18.i.hi;
        d2 = a->unk18.i.hi - b->unk18.i.hi;
        b->x_pos.i.hi = d1 + (a->x_pos.i.hi - d2);
    }
    if (a->y_pos.i.hi - a->unk1C.i.hi > 0) {
        d1 = b->y_pos.i.hi - b->unk1C.i.hi;
        d2 = a->unk1C.i.hi - b->unk1C.i.hi;
        b->y_pos.i.hi = d1 + (a->y_pos.i.hi - d2);
    }
}
