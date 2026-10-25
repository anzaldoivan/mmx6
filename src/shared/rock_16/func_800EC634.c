#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F1CC4[];

void func_800EC634(struct X4_EngineObj* arg0) {
    s16 d;

    if (background_objects[1].x_pos.i.hi > 0x400) {
        background_objects[1].x_pos.i.hi -= 0x200;
    } else {
        background_objects[1].x_pos.i.hi += 0x200;
    }
    d = (background_objects[1].x_pos.i.hi - 0x400 < 0)
            ? 0x400 - background_objects[1].x_pos.i.hi
            : background_objects[1].x_pos.i.hi - 0x400;
    if (d < 0x200) {
        D_800F1CC4[2] = 1;
        D_800F1CC4[5] = 1;
        D_800F1CC4[0] = 0;
        D_800F1CC4[1] = 0;
        background_objects[1].x_pos.i.hi = 0x400;
        background_objects[1].unk4C = 1;
        arg0->unk1 = 4;
        arg0->unk2 = 0;
        background_objects[2].unk3 = 1;
    }
    background_objects[0].x_pos.i.hi = background_objects[1].x_pos.i.hi;
    background_objects[0].unk4C = background_objects[1].unk4C;
}
