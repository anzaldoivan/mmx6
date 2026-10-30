#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

s32 random_byte();
void func_800F14D4(void*, s32);
extern s32 D_800755FC;
extern s32 D_800F6ABC;
extern s32 D_800F6AC0;
extern s32 D_800F6AC4;
extern void* D_800F6C08;

void func_800F217C(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    s16 angle;
    const u8* const* anim;

    p = D_800F6C08;
    anim = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->animation_table = anim;
    self->bg_offset = p->bg_offset;
    self->unk16 = 3;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = (void*)&D_800F6ABC;
    self->attack_box = &D_800F6AC0;
    self->hurt_box = &D_800F6AC4;
    self->collision_data = &D_800755FC;
    func_800F14D4(self, 0x16);
    self->unk15 = ((struct X4_MainObj*)D_800F6C08)->unk15;
    angle = (random_byte() % 3) * -0x1C7;
    self->x_speed = rcos(angle) * 0x10;
    self->y_speed = -rsin(angle) * 0x10;
    if (self->unk15 == 0) {
        self->x_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi - 8;
        self->x_speed = -self->x_speed;
    } else {
        self->x_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi + 8;
    }
    if (self->unk2 == 2) {
        self->y_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi - 0x18;
    } else {
        self->y_pos.i.hi = ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi + 0x10;
        self->y_speed = -self->y_speed;
    }
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 4;
    self->contact_damage = 4;
    *(s32*)((u8*)self + 0x8C) = 0;
    self->unk5 = 0;
    self->state++;
}
