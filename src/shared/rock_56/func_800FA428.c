#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA428(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].y_pos.val = 0;
        background_objects[2].unk4C = 1;
        arg0->x_pos.i.lo = 0x1F1;
        arg0->x_pos.i.hi = 4;
        arg0->unk1++;
    }
}
