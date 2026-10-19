#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800F1CC4[];

void func_800ED27C(struct X4_EngineObj* arg0) {
    if (D_800971F8[1].x_pos.i.hi < 0x400) {
        D_800971F8[1].x_pos.i.hi -= 0x200;
    } else {
        D_800971F8[1].x_pos.i.hi += 0x200;
    }
    if (D_800971F8[1].x_pos.u.hi == 0 || D_800971F8[1].x_pos.u.hi >= 0x600) {
        D_800F1CC4[1] = 1;
        D_800F1CC4[4] = 1;
        D_800F1CC4[2] = 0;
        D_800F1CC4[3] = 0;
        D_800971F8[1].x_pos.i.hi = 0x600;
        D_800971F8[1].unk4C = 1;
        arg0->unk2++;
        D_800971F8[2].unk3 = 0;
    }
    D_800971F8[0].x_pos.i.hi = D_800971F8[1].x_pos.i.hi;
    D_800971F8[0].unk4C = D_800971F8[1].unk4C;
}
