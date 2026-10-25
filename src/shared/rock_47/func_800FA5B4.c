#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA5B4(struct X4_BackgroundObj* arg0) {
    background_objects[2].x_pos.u.hi -= 0x10;
    if (background_objects[2].x_pos.i.hi <= 0) {
        background_objects[2].x_pos.u.hi = 0;
        arg0->x_pos.u.lo = 0x40;
        arg0->x_pos.u.hi = 6;
        arg0->unk1++;
    }
}
