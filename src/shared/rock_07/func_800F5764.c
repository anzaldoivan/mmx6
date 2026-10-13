#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern s32 D_80097420;
void func_800F9084();

void func_800F5764(struct X4_MainObj* self) {
    s8 t;
    s32 v;
    s32 w;

    if (!(D_80097420 & 3)) {
        func_800F6880(self, 0x10, self->x_pos.i.hi, self->y_pos.u.hi + 0x30);
    }
    t = self->animation_step.fields.event;
    if (t == 1) {
        func_800179A4(self, 0x21);
        v = 4;
        self->contact_damage = v;
        v = 0xB4;
        self->unk7E = v;
        v = (s32)func_800F9084;
        self->terrain_box = (void*)v;
        v = self->y_pos.u.hi;
        w = 0x5A;
        self->unk7C = w;
        w = (u8)self->unk6;
        self->on_screen = 0;
        *((u8*)self + 0x8D) = t;
        self->y_pos.u.hi = v + 0x20;
        self->unk6 = w + 1;
    }
}
