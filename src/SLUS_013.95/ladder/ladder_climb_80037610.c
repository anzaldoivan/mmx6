// prog SLUS_013.95 | system ladder | range 0x80037610-0x800377F8
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x80037610 update_ladder_climb_up: ladder climb up: try_leave_ladder first; turns with LEFT/RIGHT presses; UP held moves and animates; DOWN switches to the climb-down state (player_enter_ladder_climb_down).
// basis: xref derived.tsv:84; xref:caller=try_leave_ladder
// callers: update_player
// dispatch: player_action_handlers[action 15] in update_player
void update_ladder_climb_up(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_v0;
    s8 temp_s0;
    u16 temp_v1;

    if (try_leave_ladder() == 0) {
        if (self->character == 0) {
            var_v0 = try_shoot_on_ladder(arg0);
        } else if (func_801EA560(arg0) == 0) {
            var_v0 = func_801EC0F0(arg0);
        } else {
            return;
        }
        if (var_v0 == 0) {
            if (self->pressed_input & 2) {
                self->facing = 0;
            }
            if (self->pressed_input & 1) {
                self->facing = 0x40;
            }
            temp_v1 = self->input.buttons.held;
            if (temp_v1 & 4) {
                animate_object(arg0);
                move_by_velocity(arg0);
                return;
            }
            if (temp_v1 & 8) {
                temp_s0 = self->animation_step.fields.duration;
                player_set_animation_frame(arg0, 0x20,
                                           self->animation_step.fields.event);
                self->animation_step.fields.duration = temp_s0;
                player_enter_ladder_climb_down(arg0);
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x80037704 update_ladder_climb_down: ladder climb down: try_leave_ladder first; turns with LEFT/RIGHT presses; DOWN held moves and animates; UP switches to the climb-up state (player_enter_ladder_climb_up).
// basis: xref derived.tsv:85; xref:caller=try_leave_ladder
// callers: update_player
// dispatch: player_action_handlers[action 16] in update_player
void update_ladder_climb_down(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_v0;
    s8 temp_s0;
    u16 temp_v1;

    if (try_leave_ladder() == 0) {
        if (self->character == 0) {
            var_v0 = try_shoot_on_ladder(arg0);
        } else if (func_801EA560(arg0) == 0) {
            var_v0 = func_801EC0F0(arg0);
        } else {
            return;
        }
        if (var_v0 == 0) {
            if (self->pressed_input & 2) {
                self->facing = 0;
            }
            if (self->pressed_input & 1) {
                self->facing = 0x40;
            }
            temp_v1 = self->input.buttons.held;
            if (temp_v1 & 4) {
                temp_s0 = self->animation_step.fields.duration;
                player_set_animation_frame(arg0, 0x1F,
                                           self->animation_step.fields.event);
                self->animation_step.fields.duration = temp_s0;
                player_enter_ladder_climb_up(arg0);
                return;
            }
            if (temp_v1 & 8) {
                animate_object(arg0);
                move_by_velocity(arg0);
            }
        }
    }
}
