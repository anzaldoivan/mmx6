#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_80042C18(struct X4_MainObj* self);

void func_80041C24(struct X4_MainObj* self) {
    s32 r;

    func_80042C18(self);
    set_animation(self, 1);
    r = random_byte();
    self->unk6++;
    self->unk7E = r % 7 + 6;
}
