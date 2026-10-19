#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE418(struct X4_MainObj* self) {
    func_80016C48(2, 0x22, self);
    func_800179A4(self, 1);
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
