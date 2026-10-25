#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F1CC4[];

void func_800ECF14(struct X4_EngineObj* arg0) {
    if (background_objects[1].x_pos.i.hi >= 0x600) {
        background_objects[1].x_pos.i.hi += 0x200;
    } else {
        background_objects[1].x_pos.i.hi -= 0x200;
    }
    if ((u16)background_objects[1].x_pos.i.hi - 0x201 >= 0x5FFU) {
        D_800F1CC4[0] = 1;
        D_800F1CC4[3] = 1;
        D_800F1CC4[4] = 0;
        D_800F1CC4[5] = 0;
        background_objects[1].x_pos.i.hi = 0x200;
        background_objects[1].unk4C = 1;
        arg0->unk2++;
    }
    background_objects[0].x_pos.i.hi = background_objects[1].x_pos.i.hi;
    background_objects[0].unk4C = background_objects[1].unk4C;
}
