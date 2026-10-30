#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5F04();

void func_800F955C(struct X4_PlayerObj* self) {
    s8 temp_s1;

    temp_s1 = self->unk7;
    if (temp_s1 == 1) {
        func_800F5F04(self, 1);
        play_sound(2, 0x50, self);
        ((void (*)(void*, s32))set_animation)(self, 0);
        self->on_screen = temp_s1;
        self->unk7 = 0;
        self->unk6++;
    }
}
