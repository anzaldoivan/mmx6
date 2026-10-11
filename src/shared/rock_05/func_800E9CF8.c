#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern s32 D_800F3CBC;

#define SPADP ((s8**)0x1F80004C)

void func_800E9CF8(struct X4_MainObj* self) {
    u8 a;
    s32 x;
    s32 y;
    u8 t;
    s8** sp;

    sp = SPADP;
    {
        register s32 c asm("$2") = 0xC;
        self->hp = c;
    }
    a = *(u8*)&self->active;
    self->animation_table = (const u8* const*)&D_800F3CBC;
    x = self->x_pos.val;
    y = self->y_pos.val;
    self->contact_damage = 0x10;
    do {
        self->invincibility_timer = 0;
    } while (0);
    self->on_screen = 0;
    self->unk18.val = x;
    self->active = a | 0x10;
    self->unk1C.val = y;
    t = D_800970B4;
    self->unk16 = 7;
    self->air_state = 0;
    self->unk15 = 0;
    self->collision_data = &D_800743DC;
    self->hurt_box = 0;
    self->attack_box = 0;
    self->terrain_box = 0;
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    self->bg_offset = t;
    (*sp)[0x84] = 0;
    (*sp)[0x80] = -8;
    (*sp)[0x82] = 0x10;
    self->unk15 = 0;
    self->state = 1;
    self->unk5 = 2;
    self->unk6 = 0;
}
