#include "common.h"
#include "mmx6/x4.h"

void func_800F14D4(void*, s32);
extern s32 D_800755FC;
extern s32 D_800F6AB4;
extern s32 D_800F6AB8;
extern void* D_800F6C08;

void func_800F48A0(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    u8 bg;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    bg = p->bg_offset;
    self->unk16 = 4;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->bg_offset = bg;
    if (self->unk2 == 0) {
        self->hurt_box = &D_800F6AB4;
    } else {
        self->hurt_box = &D_800F6AB8;
    }
    self->collision_data = &D_800755FC;
    if (self->unk2 == 0) {
        func_800F14D4(self, 0xB);
    } else {
        func_800F14D4(self, 0xC);
    }
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0x10;
    self->contact_damage = 0;
    *(s32*)((u8*)self + 0x8C) = 0;
    *(s32*)((u8*)self + 0x90) = 0;
    self->unk5 = 0;
    self->unk6 = 0;
    self->state++;
}
