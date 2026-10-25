#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA314(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = background_objects[1].y_pos.u.hi - 0x10;
    background_objects[1].y_pos.u.hi = temp_v0;
    if ((s16)temp_v0 < 0x61) {
        background_objects[2].unk3 = 0;
        background_objects[1].y_pos.u.hi = 0x60;
        arg0->x_pos.u.lo = 0x144;
        arg0->x_pos.u.hi = 0xE;
        arg0->unk1++;
    }
}
