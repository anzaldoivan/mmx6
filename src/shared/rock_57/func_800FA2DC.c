#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA2DC(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = background_objects[0].x_pos.u.hi + 0x10;
    background_objects[0].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        background_objects[2].unk3 = 0;
        arg0->x_pos.i.lo = 0x1FD;
        arg0->x_pos.i.hi = 5;
        arg0->unk1++;
    }
}
