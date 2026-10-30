#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F1F18(struct X4_MainObj* self) {
    self->unk15 = 0;
    self->x_speed = 0x60000;
    if (!(self->collision_flags & 1)) {
        set_animation(self, 2);
    }
    self->unk6++;
}
