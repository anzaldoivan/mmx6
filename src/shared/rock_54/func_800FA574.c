#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA574(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.u.hi = 0x120;
        background_objects[1].y_pos.u.hi = 0x100;
        if (D_800CCF08 != 0) {
            background_objects[1].y_pos.u.hi = 0x300;
        }
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}
