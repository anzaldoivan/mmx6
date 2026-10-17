#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800FDE30;

#define PARENT (*(struct X4_MainObj**)((u8*)&D_800FDE30 + 0x468))

void func_800FB66C(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    struct X4_MainObj* q;
    const u8* frames;
    u8 dir;

    p = PARENT;
    self->unk40 = p->unk40;
    self->unk42 = p->unk42 & 0x7FFF;
    self->animation_table = p->animation_table;
    frames = p->sprite_frames;
    self->bg_offset = 0;
    self->unk16 = 3;
    q = PARENT;
    self->sprite_frames = frames;
    dir = q->unk15;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = 0;
    self->unk15 = dir;
    if (dir == 0) {
        self->x_pos.i.hi = PARENT->x_pos.i.hi - 0x1E;
    } else {
        self->x_pos.i.hi = PARENT->x_pos.i.hi + 0x1E;
    }
    self->y_pos.i.hi = PARENT->y_pos.i.hi - 0xA;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    ((void (*)(void*, s32))func_800179A4)(self, 0xB);
    self->hp = 0;
    self->contact_damage = 0;
    self->unk5 = 0;
    self->state++;
}

#undef PARENT
