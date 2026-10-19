#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800F1CC4[];

void func_800ECF14(struct X4_EngineObj* arg0) {
    if (D_800971F8[1].x_pos.i.hi >= 0x600) {
        D_800971F8[1].x_pos.i.hi += 0x200;
    } else {
        D_800971F8[1].x_pos.i.hi -= 0x200;
    }
    if ((u16)D_800971F8[1].x_pos.i.hi - 0x201 >= 0x5FFU) {
        D_800F1CC4[0] = 1;
        D_800F1CC4[3] = 1;
        D_800F1CC4[4] = 0;
        D_800F1CC4[5] = 0;
        D_800971F8[1].x_pos.i.hi = 0x200;
        D_800971F8[1].unk4C = 1;
        arg0->unk2++;
    }
    D_800971F8[0].x_pos.i.hi = D_800971F8[1].x_pos.i.hi;
    D_800971F8[0].unk4C = D_800971F8[1].unk4C;
}
