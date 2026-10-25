#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA2D0(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].x_pos.u.hi += 0x10;
        if ((s16)background_objects[1].x_pos.u.hi >= 0x120) {
            background_objects[1].x_pos.u.hi = 0x120;
            arg0->x_pos.u.lo = 6;
            arg0->x_pos.u.hi = 3;
            arg0->unk1++;
        }
    }
}
