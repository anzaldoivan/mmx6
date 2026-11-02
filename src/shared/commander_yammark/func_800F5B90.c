#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern struct X4_MainObj* D_800F7DEC;

void func_800F5B90(struct X4_MainObj* arg0) {
    u16 e;
    struct X4_MainObj* t = *(struct X4_MainObj**)&arg0->unk7C;

    arg0->animation_table = t->animation_table;
    arg0->unk40 = t->unk40;
    arg0->sprite_frames = t->sprite_frames;
    arg0->unk42 = t->unk42 & 0x7FFF;
    *(u8*)&arg0->bg_offset = *(u8*)&t->bg_offset;
    arg0->unk16 = 3;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = 0;
    ((void (*)(void*, s32))set_animation)(arg0, 0xF);
    arg0->unk15 = D_800F7DEC->unk15;
    arg0->x_pos.u.hi = D_800F7DEC->x_pos.u.hi;
    e = D_800F7DEC->y_pos.u.hi;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->hp = 0;
    arg0->contact_damage = 0;
    arg0->unk6 = 0;
    arg0->unk5 = 0;
    (*(u8*)&arg0->state)++;
    arg0->y_pos.u.hi = e;
}
