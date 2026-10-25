#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA460(struct X4_BackgroundObj* arg0) {
    background_objects[1].x_pos.u.hi -= 0x10;
    if ((s16)background_objects[1].x_pos.u.hi <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        arg0->x_pos.u.lo = 0x35;
        arg0->x_pos.u.hi = 4;
        arg0->unk1++;
    }
}
