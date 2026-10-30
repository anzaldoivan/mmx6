#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800ECE20(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->x_speed > 0x1FFFF) {
        self->x_speed = 0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (self->collision_flags & 1) {
        play_sound(2, 0x18, self);
        ((void (*)(s32))func_80012D9C)(3);
        self->unk7C = 0x3C;
        func_8002943C(0x3C, 2, 1);
        self->unk6 = 0;
    }
}
