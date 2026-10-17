#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800EF0B0(void*, s32);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EEDD0(struct X4_MainObj* self) {
    s32 n;
    s32 d;
    s32 e;

    func_80016C48(2, 0x21, self);
    func_800EF2E8(self);
    func_800179A4(self, 6);
    func_800EF0B0(self, 0x20);
    func_800EF0B0(self, 0x21);
    func_800EF0B0(self, 0x22);
    n = 0x300000;
    d = 0x70;
    e = 0xF;
    self->gravity = n / d;
    self->y_speed = 0x66DAA;
    self->x_accel = 0;
    if (self->unk15 == 0) {
        self->x_speed = 0x400000 / e;
    } else {
        self->x_speed = -0x400000 / e;
    }
    ((void (*)(void*))func_8002D230)(self);
    self->unk6++;
}
