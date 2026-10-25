#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA29C(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    if (*(s16*)&arg0->unk4 >= 0x79) {
        temp_v0 = background_objects[0].x_pos.u.hi + 0x10;
        background_objects[0].x_pos.u.hi = temp_v0;
        if ((s16)temp_v0 >= 0x120) {
            background_objects[0].x_pos.u.hi = 0x120;
            if (D_800CCF08 == 0) {
                arg0->x_pos.i.lo = 0x46;
            } else {
                arg0->x_pos.i.lo = 0x61;
            }
            arg0->x_pos.i.hi = 1;
            arg0->unk1++;
        }
    } else {
        (*(s16*)&arg0->unk4)++;
    }
}
