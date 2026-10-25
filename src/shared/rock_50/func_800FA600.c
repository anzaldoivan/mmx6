#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA600(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = background_objects[2].x_pos.u.hi - 0x10;
        background_objects[2].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            background_objects[2].x_pos.u.hi = 0;
            arg0->x_pos.i.lo = 0xA9;
            arg0->x_pos.i.hi = 4;
            background_objects[1].x_pos.u.hi = 0x120;
            background_objects[1].y_pos.u.hi = 0x400;
            background_objects[1].unk4C = 1;
            background_objects[1].unk3 = 1;
            arg0->unk1++;
        }
    }
}
