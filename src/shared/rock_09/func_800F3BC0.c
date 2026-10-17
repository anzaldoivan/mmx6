#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_800F3BC0(struct X4_MainObj* self) {
    if (++self->unk7C == 0x3C) {
        if (D_800970A0.x_pos.i.hi > self->x_pos.i.hi) {
            self->unk15 = 0x40;
        } else {
            self->unk15 = 0;
        }
        self->x_speed =
            (D_800970A0.x_pos.i.hi > self->x_pos.i.hi) ? 0x40000 : -0x40000;
        self->unk6 = 0xF;
    }
}
#undef D_800970A0
