#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA558(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.i.hi = 0x120;
        background_objects[2].y_pos.i.hi = 0x300;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}
