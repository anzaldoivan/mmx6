#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA33C(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].x_pos.i.hi -= 0x10;
        if (background_objects[1].x_pos.i.hi <= 0) {
            background_objects[1].x_pos.i.hi = 0;
            *(s16*)(arg0 + 8) = 0x1E7;
            *(s16*)(arg0 + 0xA) = 5;
            ((u8*)arg0)[1]++;
        }
    }
}
