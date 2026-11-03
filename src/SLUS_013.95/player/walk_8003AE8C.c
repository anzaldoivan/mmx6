// prog SLUS_013.95 | system player | range 0x8003AE8C-0x8003AED0
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

// 0x8003AE8C start_walk: enters walk start (action 3) with y speed, x acceleration and gravity cleared.
// basis: code via=action; derived.tsv:105
// callers: update_stand, func_80035D38, func_80036800, rock_01 func_801EBC60_h3, rock_01 func_801ECE08
M2C_UNK start_walk(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    player_set_animation_shooting(self, 7);
    self->y_vel.val = 0;
    self->x_accel = 0;
    self->gravity = 0;
    move_by_velocity(self);
    self->action = 3;
    self->action_phase = 0;
}
