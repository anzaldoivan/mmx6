// prog SLUS_013.95 | system movement | range 0x8003A0E8-0x8003A2C8
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

// 0x8003A0E8 check_dash_end_no_release: dash step as check_dash_end without the nothing-held end; returns 1 when the dash ends.
// basis: code via=check_dash_end; derived.tsv:182
// callers: none known
s32 check_dash_end_no_release(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 mask;
    s32 lim;
    s32 flags;

    mask = 2;
    if (self->facing != 0) {
        mask = 1;
    }
    if (self->latched_collision_flags & mask) {
        return 1;
    }
    apply_player_motion(arg0);
    if (self->facing != 0) {
        if (self->x_vel.val < self->dash_base_speed) {
            self->x_vel.val = self->dash_base_speed;
        }
    } else {
        lim = -self->dash_base_speed;
        if (lim < self->x_vel.val) {
            self->x_vel.val = lim;
        }
    }
    if (--self->dash_timer == 0) {
        return 1;
    }
    flags = self->input.buttons.held & 0x103;
    if (self->facing != 0) {
        if (flags & 2) {
            return 1;
        }
    } else if (flags & 1) {
        return 1;
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x8003A1C8 func_8003A1C8: with ride_animation set and not hurt: animation 0x26 from a standing pose, facing right, action 19.
// basis: none
// callers: update_player
void func_8003A1C8(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_a0;
    u8 temp_a1;

    if ((self->ride_animation > 0) && (self->hurt_phase <= 0)) {
        player_clear_attack();
        temp_a1 = self->unk17;
        var_a0 = temp_a1 == 5;
        if (temp_a1 == 6) {
            var_a0 = 1;
        }
        if (temp_a1 == 0xC) {
            var_a0 = 1;
        }
        if (var_a0 != 0) {
            player_set_animation(arg0, 0x26);
        }
        self->facing = 0x40;
        self->ride_animation = -1;
        self->afterimage = 0;
        self->action = 0x13;
        self->action_phase = 0;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x8003A268 func_8003A268: with hover_timer above 0: clears terrain_box, airborne, action 18 phase 1, negates hover_timer.
// basis: none
// callers: update_player
void func_8003A268(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (*(s8*)&self->hover_timer > 0) {
        func_8003CDF0();
        refresh_weapon_state(arg0);
        self->terrain_box = 0;
        self->air_state = 1;
        self->action = 0x12;
        self->action_phase = 1;
        self->hover_timer = -self->hover_timer;
    }
}
