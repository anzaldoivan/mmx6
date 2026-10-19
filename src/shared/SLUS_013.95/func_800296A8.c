#include "common.h"
#include "mmx6/x4.h"

void func_800296A8(struct X4_Unk9* arg0) {
    struct X4_BackgroundObj* obj = (struct X4_BackgroundObj*)arg0;
    s16 delta;

    delta = obj->y_pos.i.hi - obj->unk18.i.hi;
    if (delta >= 0) {
        if (delta >= obj->unk48) {
            delta = obj->unk48;
        }
        obj->y_pos.i.hi = delta + obj->unk18.i.hi;
    } else {
        if (delta < obj->unk49) {
            delta = obj->unk49;
        }
        obj->y_pos.i.hi = delta + obj->unk18.i.hi;
    }
}
