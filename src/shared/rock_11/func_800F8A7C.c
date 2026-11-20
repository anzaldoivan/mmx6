// rolefeed (3.1 T4): func_800F8A7C of src/rock_11/E9860.c
#include "common.h"
#include "mmx6/rock_11.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

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
    self->action_phase++;
}
