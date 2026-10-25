#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA428(struct X4_BackgroundObj* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[0].x_pos.u.hi += 0x10;
        if ((s16)background_objects[0].x_pos.u.hi >= 0x120) {
            {
                // !FAKE: retail keeps the shared 0x120 in the second return register
                register s32 k asm("$3") = 0x120;
                background_objects[0].x_pos.u.hi = k;
                background_objects[2].x_pos.u.hi = k;
            }
            background_objects[2].unk3 = 0;
            background_objects[2].y_pos.u.hi = 0x300;
            background_objects[2].unk4C = 1;
            if (D_800CCF08 == 0) {
                arg0->x_pos.u.lo = 0x8F;
                arg0->x_pos.u.hi = 4;
            } else {
                arg0->x_pos.u.lo = 0x99;
                arg0->x_pos.u.hi = 7;
            }
            arg0->unk1++;
        }
    }
}
