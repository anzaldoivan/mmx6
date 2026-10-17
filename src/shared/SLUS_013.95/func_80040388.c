#include "common.h"
#include "mmx6/x4.h"

#define UNK98(self) (((u8*)(self))[0x98])

void func_80040388(struct X4_MainObj* self) {
    u8 step;

    if (self->unk6 == 0) {
        self->unk6++;
        self->x_speed = 0;
        self->x_accel = 0;
        if (self->unk63 == 3) {
            self->invincibility_timer = 0x12;
        } else {
            self->invincibility_timer = 3;
        }
        UNK98(self) = 2;
    }
    step = UNK98(self);
    self->x_pos.i.hi += (s8)step;
    {
        s32 a = (s8)step;
        UNK98(self) = -a;
    }
    if ((s8)(self->invincibility_timer % 9)) {
        self->unk42 &= 0x7FFF;
    } else {
        self->unk42 |= 0x8000;
    }
    if (--self->invincibility_timer == 0) {
        self->unk5 = 1;
        self->unk6 = 0;
        self->unk42 &= 0x7FFF;
    }
}
