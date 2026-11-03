// prog SLUS_013.95 | system dash | range 0x8003B114-0x8003B214
#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"

// 0x8003B114 end_dash: Mach Dash end.
// basis: community tweaks-index.tsv:248
// callers: none known
void end_dash(s32 arg0) {
    struct X4_PlayerObj* self = (struct X4_PlayerObj*)arg0;
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    if (self->latched_collision_flags & 8) {
        self->air_state = 0;
        self->air_action = 0;
        player_clear_dash(arg0);
        if (func_8003A628((void*)arg0) == 0) {
            self->action = 2;
            self->action_phase = 0;
            if ((self->character == 0) && (self->attacking != 0)) {
                temp_v0 = self->attack_pose_timer;
                var_a2 = temp_v0 < 9U;
                if (temp_v0 < 5U) {
                    var_a2 = 2;
                }
                player_set_animation_frame((void*)arg0, 0x5E, var_a2);
                temp_v1 = self->attack_pose_timer;
                if (temp_v1 >= 9U) {
                    self->animation_step.fields.duration = (s8)(temp_v1 - 8);
                }
            } else {
                set_stand_animation_by_hp((void*)arg0);
            }
        }
    } else {
        player_set_animation_shooting(self, 0xB);
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->air_state = -1;
        self->gravity = self->base_gravity;
        if (self->dash_momentum != 0) {
            self->dash_momentum = 0;
            self->afterimage = -1;
        }
        self->action = 7;
        self->action_phase = 0;
    }
}
