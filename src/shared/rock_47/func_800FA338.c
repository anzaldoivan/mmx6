#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA338(struct X4_MainObj* self) {
    if (func_800EA480((s8*)self) != 0) {
        D_800971F8[2].y_pos.i.hi = 0;
        D_800971F8[2].unk4C = 1;
        D_800971F8[1].unk3 = 0;
        self->x_pos.i.lo = 0x29;
        self->x_pos.i.hi = 0xA;
        self->id++;
    }
}
