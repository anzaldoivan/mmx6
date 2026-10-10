#include "common.h"
#include "mmx6/x4.h"

void func_800F14D4(void*, s32);
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

#define OWNER ((struct X4_MainObj*)D_800F6C08)

void func_800F2C7C(struct X4_MainObj* self) {
    struct X4_MainObj* p;
    const u8* const* tbl;
    u8 bg;

    p = D_800F6C08;
    tbl = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->animation_table = tbl;
    bg = p->bg_offset;
    self->unk16 = 2;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = 0;
    self->bg_offset = bg;
    func_800F14D4(self, 0x1A);
    self->unk15 = OWNER->unk15;
    if (self->unk2 == 10) {
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
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->contact_damage = 0;
    self->unk5 = 0;
    self->state++;
}

#undef OWNER
