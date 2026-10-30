#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F815C(struct X4_AnimatedObj* self) {
    struct X4_BackgroundObj* bg;
    s8 ev = self->animation_step.fields.event;

    if (ev == 1) {
        play_sound(2, 0x59, self);
        set_animation(self, 0xC);
        bg = background_objects;
        self->x_pos.i.hi = bg->x_pos.i.hi + 0xA0;
        self->y_pos.i.hi = bg->y_pos.i.hi + 0x20;
        func_800F9E04(self);
        self->unk6++;
    } else if (ev == 2) {
        play_sound(2, 0x59, self);
    } else if (ev == 3) {
        play_sound(2, 0x51, self);
    }
}
