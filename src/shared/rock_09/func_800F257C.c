#include "common.h"
#include "mmx6/x4.h"

s32 random_byte();
void func_800F14D4(void*, s32);
extern s32 D_800755FC;
extern s32 D_800F6AC8;
extern s32 D_800F6ACC;
extern s16 D_800F6AD8[];
extern s16 D_800F6B18[];
extern void* D_800F6C08;

void func_800F257C(struct X4_MainObj* self) {
    struct X4_MainObj* p;

    p = D_800F6C08;
    self->animation_table = p->animation_table;
    self->unk42 &= 0x7FFF;
    self->bg_offset = p->bg_offset;
    self->unk16 = 3;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = &D_800F6AC8;
    self->hurt_box = &D_800F6ACC;
    self->collision_data = &D_800755FC;
    func_800F14D4(self, 0x17);
    if (self->unk2 == 4) {
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
        self->x_speed = 0x20000;
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
        self->x_speed = -0x20000;
        self->unk15 = 0;
    }
    self->y_speed = (random_byte() % 4 << 16) + 0x50000;
    self->x_accel = 0;
    self->gravity = 0x3000;
    self->hp = 4;
    self->contact_damage = 4;
    self->unk5 = 0;
    self->state++;
}
