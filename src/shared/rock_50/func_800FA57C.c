#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA57C(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (func_800EA480((s8*)arg0) != 0) {
        temp_v0 = background_objects[1].x_pos.u.hi - 0x10;
        background_objects[1].x_pos.u.hi = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            background_objects[2].x_pos.u.hi = 0x120;
            background_objects[2].y_pos.u.hi = 0x300;
            background_objects[1].x_pos.u.hi = 0;
            background_objects[2].unk4C = 1;
            arg0->x_pos.i.lo = 0xA3;
            arg0->x_pos.i.hi = 6;
            *(s16*)&arg0->unk4 = 0;
            arg0->unk1++;
        }
    }
}
