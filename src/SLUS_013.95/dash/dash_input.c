// prog SLUS_013.95 | system dash | range 0x80039EB0-0x80039F74
#include "common.h"
#include "mmx6/x4.h"

// 0x80039EB0 check_dash_input: dash input incl. double tap.
// basis: community tweaks-index.tsv:243
// callers: player_check_dash_jump_walk, start_falcon_dash, try_start_air_dash
s32 check_dash_input(struct X4_PlayerObj* arg0) {
    if ((arg0->move_lock != 0) ||
        ((arg0->double_tap_dash == 0) && !(arg0->pressed_input & 0x100))) {
        return 0;
    }
    if (arg0->input.buttons.held & 1) {
        arg0->facing = 0x40;
    }
    if (arg0->input.buttons.held & 2) {
        arg0->facing = 0;
    }
    if (arg0->facing != 0) {
        if (arg0->latched_collision_flags & 1) {
            return 0;
        }
        arg0->x_vel.val = arg0->dash_speed;
    } else {
        if (arg0->latched_collision_flags & 2) {
            return 0;
        }
        arg0->x_vel.val = -arg0->dash_speed;
    }
    return 1;
}
