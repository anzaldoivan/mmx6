#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);

void func_800ECE7C(struct X4_PlayerObj* self) {
    ((void (*)(void*))func_8002D230)(self);
    if (self->y_vel.val <= -0x40000) {
        self->y_vel.val = -0x40000;
    }
    if (self->unk70 != 0 || (func_8002EE10(self), self->unk70 != 0)) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x4D, self);
        self->x_vel.val = -0x10000;
        self->y_vel.val = 0x15555;
        self->unk70 = 0;
        self->unk2C = 0xB60;
        self->unk7++;
        func_8002D230(self);
    }
}
