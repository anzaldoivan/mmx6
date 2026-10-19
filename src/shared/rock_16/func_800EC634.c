#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800F1CC4[];

void func_800EC634(struct X4_EngineObj* arg0) {
    s16 d;

    if (D_800971F8[1].x_pos.i.hi > 0x400) {
        D_800971F8[1].x_pos.i.hi -= 0x200;
    } else {
        D_800971F8[1].x_pos.i.hi += 0x200;
    }
    d = (D_800971F8[1].x_pos.i.hi - 0x400 < 0)
            ? 0x400 - D_800971F8[1].x_pos.i.hi
            : D_800971F8[1].x_pos.i.hi - 0x400;
    if (d < 0x200) {
        D_800F1CC4[2] = 1;
        D_800F1CC4[5] = 1;
        D_800F1CC4[0] = 0;
        D_800F1CC4[1] = 0;
        D_800971F8[1].x_pos.i.hi = 0x400;
        D_800971F8[1].unk4C = 1;
        arg0->unk1 = 4;
        arg0->unk2 = 0;
        D_800971F8[2].unk3 = 1;
    }
    D_800971F8[0].x_pos.i.hi = D_800971F8[1].x_pos.i.hi;
    D_800971F8[0].unk4C = D_800971F8[1].unk4C;
}
