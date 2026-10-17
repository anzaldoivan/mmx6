#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80042A9C(struct X4_MainObj* self, s32 arg1);
void func_80042C18(struct X4_MainObj* self);
s32 func_80065944(s32);
extern s32 D_80097420;

void func_80042420(struct X4_MainObj* self) {
    s16 y;

    y = M2C_FIELD(self, u16*, 0x86) +
        (func_80065944((D_80097420 & 0x7F) << 5) >> 9);
    self->y_pos.i.hi = y;
    if (--self->unk7C == 0) {
        if ((self->unk2 & 0xF0) == 0x30) {
            self->unk7C = 0x1E;
            self->unk6 = 6;
            return;
        }
        M2C_FIELD(self, u8*, 0x8E) = 0;
        self->attack_box = 0;
        self->hurt_box = 0;
        self->on_screen = 0;
        func_80042C18(self);
        self->unk7 = 0;
        func_80042A9C(self, 0);
        func_80042A9C(self, 1);
        self->unk6++;
    }
}
