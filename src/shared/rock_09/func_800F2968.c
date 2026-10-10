#include "common.h"
#include "mmx6/x4.h"

void func_800F14D4(void*, s32);
extern s32 D_800755FC;
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

#define OWNER ((struct X4_MainObj*)D_800F6C08)

void func_800F2968(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    u8 bg;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    bg = p->bg_offset;
    self->unk16 = 3;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = &D_800755FC;
    self->bg_offset = bg;
    func_800F14D4(self, 0x19);
    self->unk15 = OWNER->unk15;
    if (self->unk2 == 8) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi +
                D_800F6AD8[OWNER->animation_step.fields.frame_index * 2];
        } else {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi -
                D_800F6AD8[OWNER->animation_step.fields.frame_index * 2];
        }
        self->y_pos.i.hi =
            OWNER->y_pos.i.hi +
            D_800F6AD8[OWNER->animation_step.fields.frame_index * 2 + 1];
    } else {
        if (self->unk15 == 0) {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi +
                D_800F6B18[OWNER->animation_step.fields.frame_index * 2];
        } else {
            self->x_pos.i.hi =
                OWNER->x_pos.i.hi -
                D_800F6B18[OWNER->animation_step.fields.frame_index * 2];
        }
        self->y_pos.i.hi =
            OWNER->y_pos.i.hi +
            D_800F6B18[OWNER->animation_step.fields.frame_index * 2 + 1];
    }
    self->y_speed = 0x80000;
    self->x_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 4;
    self->contact_damage = 4;
    self->unk5 = 0;
    self->state++;
}

#undef OWNER
