#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE774(struct X4_MainObj* self) {
    u32 r;

    set_animation(self, 2);
    func_800EF2E8(self);
    r = random_byte();
    self->unk6++;
    self->unk7C = (u8)(r % 3) + 1;
}
