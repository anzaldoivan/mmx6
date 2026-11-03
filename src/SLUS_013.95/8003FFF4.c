// prog SLUS_013.95 | system movement | range 0x8003FFF4-0x80040300
// 0x8003FFF4 update_special_charge: charge-path step of update_player_charge, asm body not yet read.
// basis: code via=special_charge_timer; derived.tsv:164
// callers: update_player_charge
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 play_sound(s32, s32, void*);

void update_special_charge(struct X4_PlayerObj* self) {
    s32 full;
    s32 half;
    s32 t;
    s32 v;

    if (!(self->input.buttons.held & 0x20)) {
        if (!(D_800CCF99 & 1)) {
            return;
        }
        if (self->weapon != 0) {
            return;
        }
    }
    if (self->charge_state[1] == 2) {
        return;
    }
    full = 0x5A;
    half = 0x19;
    t = self->special_charge_timer + 1;
    self->special_charge_timer = t;
    if (self->equipped_parts & 0x100000) {
        full = 0x2D;
        half = 0xC;
    }
    v = t & 0xFF;
    if (v == half) {
        play_sound(1, 7, self);
        self->charge_state[1] = 1;
        return;
    }
    if (v == full) {
        self->charge_state[1] = 2;
    }
}

#include "common.h"
#include "mmx6/globals.h"

s8 get_shot_limit(struct X4_PlayerObj* arg0, s8 arg1) {
    s8 v = shot_limits[arg1];

    if (arg0->equipped_parts & 0x40000) {
        v = D_800740B4[arg1];
    }
    return v;
}

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#define M2C_UNK s32

void func_800400F4(void* arg0) {
    struct X4_MainObj* self = arg0;
    s32 v;

    if (self->action_phase == 0) {
        self->action_phase++;
        if (D_800970A8 < self->x_pos.val) {
            self->x_speed = D_800741F4[self->unk63 - 5];
        } else {
            self->x_speed = -D_800741F4[self->unk63 - 5];
        }
        self->x_accel = 0x3000;
        self->y_speed = 0;
        self->gravity = 0;
        if (self->unk63 == 5) {
            self->invincibility_timer = 0x12;
        } else {
            self->invincibility_timer = 1;
        }
    }
    apply_object_motion(arg0);
    v = self->x_speed;
    if ((v < 0 ? -v : v) < 0x6000) {
        self->x_speed = 0;
        self->x_accel = 0;
    }
    if (self->collision_flags & 3) {
        self->x_speed = 0;
        self->x_accel = 0;
    }
    if ((s8)((s8) * (u8*)&self->invincibility_timer % 9) != 0) {
        self->unk42 &= 0x7FFF;
    } else {
        self->unk42 |= 0x8000;
    }
    if (--self->invincibility_timer == 0) {
        self->action = 1;
        self->action_phase = 0;
        self->x_speed = 0;
        self->x_accel = 0;
        self->unk42 &= 0x7FFF;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/3CE30", func_80040290);
// clang-format on
