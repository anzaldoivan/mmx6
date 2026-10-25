#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEED;

void func_800E9E88(struct X4_AnimatedObj* arg0) {
    if (D_800CCEED != 0) {
        background_objects[1].unk42 = 0x140;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4 = 5;
        background_objects[2].x_pos.i.hi = background_objects[1].x_pos.i.hi / 4;
        background_objects[2].y_pos.i.hi = 0x1C0;
        background_objects[2].unk4C = 1;
        arg0->state++;
    }
}
