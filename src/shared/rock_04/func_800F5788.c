#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F5788(struct X4_MainObj* self) {
    s8 v;

    self->unk16 = 4;
    ((void (*)(void*, s32))set_animation)(self, 0x1A);
    v = self->unk2;
    if (v == 0) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi -= 0x18;
        } else {
            self->x_pos.i.hi += 0x18;
        }
        self->y_pos.i.hi -= 8;
    } else if (v == 1) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi -= 0x1E;
        } else {
            self->x_pos.i.hi += 0x1E;
        }
        self->y_pos.i.hi += 8;
    } else if (v == 2) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi -= 0x18;
        } else {
            self->x_pos.i.hi += 0x18;
        }
        self->y_pos.i.hi += 8;
    }
    self->on_screen = 0;
    self->state = 1;
    self->unk5 = 0;
    self->unk6 = 0;
}
