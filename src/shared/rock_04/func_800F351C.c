#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(void*);
extern s16 D_800970AA;

void func_800F351C(struct X4_MainObj* self) {
    s32 v;
    u8 t;

    move_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (55/57)
        register s32 f asm("$2") = self->unk15;
        if (f == 0) {
            if (D_800970AA >= self->x_pos.i.hi || (self->collision_flags & 2)) {
                func_800179A4(self, 0x17);
                t = self->unk6;
                v = 0xFFFE0000;
                self->x_speed = v;
                self->unk7C = 0x10;
                self->unk6 = t + 1;
                return;
            }
        } else if (D_800970AA <= self->x_pos.i.hi ||
                   (self->collision_flags & 1)) {
            func_800179A4(self, 0x17);
            t = self->unk6;
            v = 0x20000;
            self->x_speed = v;
            self->unk7C = 0x10;
            self->unk6 = t + 1;
            return;
        }
    }
    if (self->animation_step.fields.event == 2) {
        func_80016C48(2, 0x12, self);
    }
}
