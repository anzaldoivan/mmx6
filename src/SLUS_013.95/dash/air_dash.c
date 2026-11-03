// prog SLUS_013.95 | system dash | range 0x8003906C-0x80039224
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"

static inline s32 func_8003906C_inl(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->double_tap_dash == 0 && !(self->pressed_input & 0x100)) {
        return 0;
    }
    if (self->input.buttons.held & 1) {
        self->facing = 0x40;
    }
    if (self->input.buttons.held & 2) {
        self->facing = 0;
    }
    if (self->facing != 0) {
        if (self->latched_collision_flags & 1) {
            return 0;
        }
        self->x_vel.val = self->dash_speed;
    } else {
        if (self->latched_collision_flags & 2) {
            return 0;
        }
        self->x_vel.val = -self->dash_speed;
    }
    return 1;
}

// 0x8003906C select_air_dash: air dash picked by armor.
// basis: community tweaks-index.tsv:216
// callers: handle_jump_rise
s32 select_air_dash(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 t;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->air_action != 0) {
        return 0;
    }
    if (self->character == 0) {
        t = self->armor;
        if (t == 1) {
            return start_falcon_dash(arg0) != 0;
        }
        if (t == 3) {
            if (try_start_air_dash(arg0) != 0) {
                return 1;
            }
        } else if (start_hover(arg0) != 0) {
            return 1;
        }
    } else if (func_801EC298(arg0) != 0) {
        return 1;
    }
    if (self->character == 0) {
        if (self->shot_cooldown != 0) {
            return 0;
        }
        if (self->armor != 4) {
            return 0;
        }
    }
    if (func_8003906C_inl(arg0) != 0) {
        func_8003B298(arg0);
        return 1;
    }
    return 0;
}
