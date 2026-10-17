#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230();

void func_800F4AB4(struct X4_MainObj* self) {
    if (self->collision_flags & 8) {
        self->x_pos.i.hi += 6;
        self->y_pos.i.hi -= 0x18;
        func_800179A4(self, 7);
        {
            // !FAKE: pin keeps the increment temp in the second return register
            register s32 t asm("$3") = (u8)self->unk6 + 1;
            // !FAKE: pin keeps the stored constant in the first return register
            register s32 k asm("$2") = 1;
            self->on_screen = k;
            self->unk7C = 0xB4;
            self->unk6 = t;
        }
        return;
    }
    func_8002D230(self);
}
