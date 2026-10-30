#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
void func_800F9E04(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F7FFC(struct X4_AnimatedObj* self) {
    s8 mode = ((s8*)self)[0x45];
    struct X4_BackgroundObj* bg;

    if (mode == 1) {
        play_sound(2, 0x59, self);
        ((void (*)(void*, s32))set_animation)(self, 0xC);
        bg = background_objects;
        if (self->x_pos.i.hi >= bg->x_pos.i.hi + 0xA0) {
            // !FAKE: depin: dropping it breaks the match (52/54)
            register s16 x asm("$3") = bg->x_pos.i.hi + 0x40;
            self->x_pos.i.hi = x;
        } else {
            // !FAKE: depin: dropping it breaks the match (48/54)
            register s16 x asm("$3") = bg->x_pos.i.hi + 0x100;
            self->x_pos.i.hi = x;
        }
        self->y_pos.i.hi = bg->y_pos.i.hi + 0x50;
        do {
            func_800F9E04(self);
        } while (0);
        self->unk6 = 2;
    } else if (mode == 2) {
        play_sound(2, 0x59, self);
    } else if (mode == 3) {
        play_sound(2, 0x51, self);
    }
}
