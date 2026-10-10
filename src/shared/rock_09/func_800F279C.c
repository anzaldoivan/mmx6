#include "common.h"
#include "mmx6/x4.h"

void func_800F14D4(void*, s32);
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

void func_800F279C(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->bg_offset = p->bg_offset;
    self->unk16 = 2;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->collision_data = 0;
    func_800F14D4(self, 0x18);
    if (self->unk2 == 6) {
        if (((struct X4_MainObj*)D_800F6C08)->unk15 == 0) {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi +
                D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        } else {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi -
                D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        }
        self->y_pos.i.hi =
            ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi +
            D_800F6AD8[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2 +
                       1];
        self->unk15 = 0x40;
    } else {
        if (((struct X4_MainObj*)D_800F6C08)->unk15 == 0) {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi +
                D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        } else {
            self->x_pos.i.hi =
                ((struct X4_MainObj*)D_800F6C08)->x_pos.i.hi -
                D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2];
        }
        self->y_pos.i.hi =
            ((struct X4_MainObj*)D_800F6C08)->y_pos.i.hi +
            D_800F6B18[((struct X4_MainObj*)D_800F6C08)
                               ->animation_step.fields.frame_index *
                           2 +
                       1];
        self->unk15 = 0;
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
