#include "common.h"
#include "mmx6/x4.h"

// 0x80039D7C check_walk_input: walk input: L or R held sets facing and x_vel to +-walk_speed unless a wall blocks that side; returns 1 when set.
// basis: xref derived.tsv:96; xref:caller=player_check_dash_jump_walk
// callers: player_check_dash_jump_walk
s32 check_walk_input(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u16 temp_v1;

    if (self->move_lock != 0) {
        return 0;
    }
    temp_v1 = self->input.buttons.held;
    if (!(temp_v1 & 3)) {
        return 0;
    }
    if (temp_v1 & 1) {
        self->facing = 0x40;
        if (self->latched_collision_flags & 1) {
            return 0;
        }
        self->x_vel.val = self->walk_speed;
    } else {
        self->facing = 0;
        if (self->latched_collision_flags & 2) {
            return 0;
        }
        self->x_vel.val = -self->walk_speed;
    }
    return 1;
}
