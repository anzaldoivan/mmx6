#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_80042C18(struct X4_MainObj* self);

void func_80041F6C(struct X4_MainObj* self) {
    func_80042C18(self);
    set_animation(self, 0);
    self->unk7C = 0x3C;
    {
        // !FAKE: pin the increment temp to the first return register
        register s32 t asm("$2") = (u8)self->unk6 + 1;
        self->unk6 = t;
    }
}
