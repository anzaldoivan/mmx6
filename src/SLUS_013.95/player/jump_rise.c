// prog SLUS_013.95 | system player | range 0x80035620-0x800357A4
#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"

#include "mmx6/sound.h"
#include "mmx6/graphics.h"
#include "mmx6/dash.h"
#include "mmx6/cling.h"
#include "mmx6/pilot_globals.h"

// 0x80035620 handle_jump_rise: jump rising state.
// basis: community tweaks-index.tsv:231
// callers: update_player
// dispatch: player_action_handlers[action 6] in update_player
void handle_jump_rise(struct X4_PlayerObj* arg0) {
    s32 var_v0;

    if (arg0->move_lock != 0) {
        arg0->y_vel.val = 0;
    }
    if (arg0->latched_collision_flags & 4) {
        arg0->y_vel.val = 0;
    }
    if (!(arg0->input.buttons.held & 0x80)) {
        arg0->y_vel.val = 0;
    }
    if (arg0->character == 0) {
        var_v0 = try_shoot_in_air(arg0);
    } else if ((func_801EA560(arg0) == 0) && (func_801EA454(arg0) == 0)) {
        var_v0 = func_801EBF94(arg0);
    } else {
        return;
    }
    if (var_v0 == 0) {
        animate_object(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (93/98)
            register s32 t asm("$2") = arg0->animation_step.fields.event & 0x80;
            if (t) {
                *(u8*)&arg0->animation_step.fields.event =
                    (u8)(*(u8*)&arg0->animation_step.fields.event & 0x3F);
                play_sound(1, 1, arg0);
            }
        }
        if ((try_grab_ladder_from_air(arg0) == 0) &&
            (func_80039984(arg0) == 0)) {
            if (arg0->wall_cling_delay == 0) {
                if (try_enter_wall_cling(arg0) != 0) {
                    return;
                }
            } else {
                --*(u8*)&arg0->wall_cling_delay;
            }
            if (select_air_dash(arg0) == 0) {
                set_air_x_velocity(arg0);
                func_8003D394(arg0);
                if (arg0->y_vel.val <= 0) {
                    player_set_animation_shooting(arg0, 0xB);
                    {
                        s32 m = -1;
                        s32 n = 7;
                        arg0->air_state = m;
                        *(u8*)&arg0->action = n;
                    }
                    *(u8*)&arg0->action_phase = 0;
                    return;
                }
                func_8003F508(arg0, 0xA);
            }
        }
    }
}
