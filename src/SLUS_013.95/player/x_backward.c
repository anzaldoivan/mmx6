// prog SLUS_013.95 | system player | range 0x80037A60-0x80037B0C
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

s32 apply_player_motion(void* arg); /* extern */

// 0x80037A60 move_x_backward: x motion that only goes backward: stops x at a wall ahead in the motion, moves, then drops an x_vel that points the way the player faces.
// basis: code via=facing; derived.tsv:87
// callers: update_hurt_knockback
// unnamed callers: func_80035BDC
void move_x_backward(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 temp_v0;
    s32 var_v1;

    if (self->ride_animation == 0) {
        temp_v0 = self->x_vel.val;
        if (temp_v0 != 0) {
            var_v1 = 2;
            if (temp_v0 > 0) {
                var_v1 = 1;
            }
            if (self->latched_collision_flags & var_v1) {
                self->x_vel.val = 0;
                self->x_accel = 0;
            }
        }
        apply_player_motion(arg0);
        if (self->facing != 0) {
            if (self->x_vel.val > 0) {
                self->x_vel.val = 0;
                self->x_accel = 0;
            }
        } else if (self->x_vel.val < 0) {
            self->x_vel.val = 0;
            self->x_accel = 0;
        }
    }
}
