#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EEAC4(struct X4_MainObj* self) {
    if (self->unk7 == 0) {
        set_animation(self, 5);
        {
            // !FAKE: constant 1 in the first return register keeps the counter load after the flag store
            register s32 one asm("$2") = 1;
            self->on_screen = one;
        }
        self->x_accel = 0;
        self->x_speed = 0;
        self->gravity = 0x3000;
        self->unk6++;
    }
}
