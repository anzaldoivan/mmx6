#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
extern struct X4_BackgroundObj background_objects[3];

void func_800F8A7C(struct X4_MainObj* self) {
    struct X4_BackgroundObj* bg;

    play_sound(2, 0x48, self);
    set_animation(self, 5);
    bg = &background_objects[0];
    self->x_pos.i.hi = bg->unk26 + 0xA8;
    self->y_pos.i.hi = bg->unk2A + 0x90;
    func_800FA4C8(self);
    self->unk6++;
}
