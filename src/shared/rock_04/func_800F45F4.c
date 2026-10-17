#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_8009721E;

void func_800F45F4(struct X4_MainObj* self) {
    if (self->x_pos.i.hi >= D_8009721E + 0xC0) {
        self->unk15 = 0;
    } else {
        self->unk15 = 0x40;
    }
    ((void (*)(void*, s32))func_800179A4)(self, 0x11);
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    self->unk6++;
}
