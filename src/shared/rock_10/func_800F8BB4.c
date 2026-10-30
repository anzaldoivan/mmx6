#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F8BB4(struct X4_AnimatedObj* self) {
    s8 mode = ((s8*)self)[0x45];

    if (mode == 1) {
        play_sound(2, 0x59, self);
        set_animation(self, 0xC);
        func_800F9E04(self);
        self->unk15 = 0x40;
        self->x_pos.i.hi = background_objects[0].x_pos.i.hi + 0xA0;
        self->y_pos.i.hi = background_objects[0].y_pos.i.hi + 0x40;
        self->unk6++;
    } else if (mode == 2) {
        play_sound(2, 0x59, self);
    } else if (mode == 3) {
        play_sound(2, 0x51, self);
    }
}
