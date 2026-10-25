#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_80029780(struct X4_BackgroundObj* arg0) {
    struct X4_BackgroundObj* bg = background_objects;

    arg0->x_pos.i.hi = bg->x_pos.i.hi + arg0->unk40;
    arg0->y_pos.i.hi = bg->y_pos.i.hi + arg0->unk42;
}
