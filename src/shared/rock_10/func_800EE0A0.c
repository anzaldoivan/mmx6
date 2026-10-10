#include "common.h"
#include "mmx6/x4.h"

s32 func_800179A4(void*, s32);
extern u8 D_800FC15C[];

void func_800EE0A0(struct X4_MainObj* self) {
    struct X4_MainObj* parent;

    parent = (struct X4_MainObj*)self->attack_box;
    self->on_screen = 1;
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    self->unk16 = 0;
    self->unk40 = parent->unk40;
    self->unk42 = parent->unk42 & 0x7FFF;
    self->animation_table = parent->animation_table;
    self->sprite_frames = parent->sprite_frames;
    self->unk15 = parent->unk15;
    self->bg_offset = parent->bg_offset;
    ((void (*)(void*, s32))func_800179A4)(self, 7);
    switch (self->unk2 & 0xFE) {
    case 2:
    case 4:
    case 6:
        self->x_pos.i.hi += (s8)D_800FC15C[6];
        self->y_pos.i.hi += (s8)D_800FC15C[7];
        break;
    case 10:
    case 12:
    case 14:
        self->x_pos.i.hi += (s8)D_800FC15C[4];
        self->y_pos.i.hi += (s8)D_800FC15C[5];
        break;
    case 8:
        self->x_pos.i.hi += (s8)D_800FC15C[8];
        self->y_pos.i.hi += (s8)D_800FC15C[9];
        break;
    case 18:
    case 20:
    case 22:
        self->x_pos.i.hi += (s8)D_800FC15C[12];
        self->y_pos.i.hi += (s8)D_800FC15C[13];
        break;
    case 26:
    case 28:
    case 30:
        self->x_pos.i.hi += (s8)D_800FC15C[14];
        self->y_pos.i.hi += (s8)D_800FC15C[15];
        break;
    case 24:
        self->x_pos.i.hi += (s8)D_800FC15C[10];
        self->y_pos.i.hi += (s8)D_800FC15C[11];
        break;
    default:
        if (self->unk15 & 0x40) {
            self->x_pos.i.hi += (s8)D_800FC15C[2];
            self->y_pos.i.hi += (s8)D_800FC15C[3];
        } else {
            self->x_pos.i.hi += (s8)D_800FC15C[0];
            self->y_pos.i.hi += (s8)D_800FC15C[1];
        }
        break;
    }
    self->state++;
}
