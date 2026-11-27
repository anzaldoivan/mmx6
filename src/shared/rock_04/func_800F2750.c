// rolefeed (3.1 T4): func_800F2750 of src/rock_04/E9860.c
#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 func_80030ECC();
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7518[])(void*);

// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern s32 D_800F769C;

void func_800F2750(struct X4_MainObj* self) {
    s8 one;
    s32 kind;

    one = M2C_FIELD(self, struct X4_MainObj**, 0x7C)->state;
    if (one != 1) {
        self->state = 2;
        self->on_screen = 0;
        return;
    }
    kind = self->unk2 & 0xF0;
    self->contact_damage = 0;
    self->hp = one;
    self->unk16 = 4;
    self->air_state = one;
    self->collision_data = &D_8007433C;
    self->terrain_box = 0;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->on_screen = 0;
    self->state = one;
    self->action = 0;
    self->action_phase = 0;
    self->unk7 = 0;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    if (kind == 0) {
        ((void (*)(void*, s32))set_animation)(self, 0x1B);
        self->collision_data = D_800741FC;
        self->hurt_box = 0;
        self->attack_box = 0;
        self->terrain_box = 0;
        self->contact_damage = 4;
        self->hp = 2;
        self->unk16 = 4;
        if (self->unk2 == 0) {
            if (self->unk15 == 0) {
                self->x_pos.u.hi -= 0x18;
            } else {
                self->x_pos.u.hi += 0x18;
            }
            self->y_pos.u.hi -= 8;
        } else if (self->unk2 == one) {
            if (self->unk15 == 0) {
                self->x_pos.u.hi -= 0x1E;
            } else {
                self->x_pos.u.hi += 0x1E;
            }
            self->y_pos.u.hi += 8;
        } else if (self->unk2 == 2) {
            if (self->unk15 == 0) {
                self->x_pos.u.hi -= 0x18;
            } else {
                self->x_pos.u.hi += 0x18;
            }
            self->y_pos.u.hi += 8;
        }
        self->action = 2;
    } else if (kind == 0x10) {
        self->collision_data = D_800741FC;
        self->hurt_box = 0;
        self->attack_box = 0;
        self->terrain_box = 0;
        self->contact_damage = 2;
        self->hp = one;
        self->unk16 = 4;
        self->unk15 = 0;
        self->action = 0;
    } else if (kind == 0x20) {
        self->hurt_box = 0;
        self->attack_box = 0;
        self->terrain_box = (void*)&D_800F769C;
        self->unk15 = 0;
        self->action = one;
    }
}
