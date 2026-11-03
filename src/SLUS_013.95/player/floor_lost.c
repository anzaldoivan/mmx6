// prog SLUS_013.95 | system player | range 0x80039DFC-0x80039EAC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#define M2C_UNK s32

// 0x80039DFC check_floor_lost: grounded (air_state 0) with no floor contact, not hurt, hovering or riding: falls through func_8003AFF4.
// basis: code via=latched_collision_flags; derived.tsv:97
// callers: update_player
void check_floor_lost(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 temp_v1;

    temp_v1 = self->action;
    if (temp_v1 == 0) {
        return;
    }
    if (temp_v1 == 1) {
        return;
    }
    if ((self->air_state == 0) && (self->hurt_phase <= 0) &&
        (*(s8*)&self->hover_timer >= 0) && (self->ride_animation == 0) &&
        !(self->latched_collision_flags & 8)) {
        if (self->character != 0) {
            player_clear_attack();
        }
        func_8003AFF4((s32)arg0);
        set_pose_size(arg0);
    }
}
