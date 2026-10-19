#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s32 D_8009719C;

M2C_UNK func_8002D230(struct X4_MainObj* self) {
    s32 vy;
    s32* vyp;

    self->x_pos.val += self->x_speed;
    self->y_pos.val -= self->y_speed;
    if (self->unk15 != 0) {
        self->x_speed = self->x_speed + self->x_accel;
    } else {
        self->x_speed = self->x_speed - self->x_accel;
    }
    vyp = &self->y_speed;
    vy = *vyp - self->gravity;
    *vyp = vy;
    if (vy < D_8009719C) {
        *vyp = D_8009719C;
    }
}
