#include "common.h"
#include "mmx6/x4.h"

extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800FA538(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = *(struct X4_MainObj**)((u8*)self + 0x8C);
    {
        s32 d = (p->x_pos.u.hi - D_80097202) - 0x140;
        self->x_pos.i.hi = D_80097202 - d;
    }
    self->y_pos.i.hi = p->y_pos.i.hi;
    self->animation_step.fields.frame_index =
        p->animation_step.fields.frame_index;
    self->on_screen = p->on_screen;
    if (p->unk15 == 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    if (p->state != 1) {
        self->state = 3;
    }
}
#undef D_80097202
