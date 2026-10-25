#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA500(struct X4_BackgroundObj* arg0) {
    background_objects[0].x_pos.u.hi += 0x10;
    if (background_objects[0].x_pos.i.hi >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        background_objects[2].unk3 = 0;
        arg0->x_pos.u.lo = 0x39;
        arg0->x_pos.u.hi = 7;
        arg0->unk1++;
    }
}
