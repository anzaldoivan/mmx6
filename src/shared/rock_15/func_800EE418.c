#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE418(struct X4_MainObj* self) {
    play_sound(2, 0x22, self);
    set_animation(self, 1);
    func_800EF2E8(self);
    if (self->unk15 != 0) {
        self->x_speed = 0x4000;
    } else {
        self->x_speed = -0x4000;
    }
    {
        // !FAKE: keeps the counter read ahead of the constant stores
        register s32 t asm("$3") = (u8)self->unk6 + 1;

        self->unk7C = 0x32;
        self->y_speed = 0;
        self->unk7E = 2;
        self->unk6 = t;
    }
}
