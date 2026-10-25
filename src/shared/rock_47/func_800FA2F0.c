#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA2F0(struct X4_MainObj* self) {
    background_objects[1].x_pos.u.hi -= 0x10;
    if ((s16)background_objects[1].x_pos.u.hi <= 0) {
        background_objects[1].x_pos.u.hi = 0;
        self->x_pos.i.lo = 0x27;
        self->x_pos.i.hi = 2;
        self->id++;
    }
}
