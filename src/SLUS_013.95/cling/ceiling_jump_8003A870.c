// prog SLUS_013.95 | system cling | range 0x8003A870-0x8003A97C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"

// 0x8003A870 check_ceiling_jump: ceiling jump input (Shadow legs, Zero Hyoroga).
// basis: community tweaks-index.tsv:192
// callers: update_stand, update_fall, update_landing, update_dash_phase1
// unnamed callers: func_800354E8
s32 check_ceiling_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->character != 0) {
        if (!(self->beaten_stages & 2)) {
            return 0;
        }
    } else if (self->armor != 2) {
        return 0;
    }
    if (!(self->input.buttons.held & 4)) {
        return 0;
    }
    if (self->pressed_input & 0x80) {
        self->air_state = 1;
        self->x_vel.val = 0;
        self->y_vel.val = self->jump_speed * 2;
        player_set_animation_shooting(arg0, 0xA);
        self->wall_cling_delay = 0xA;
        refresh_weapon_state(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (66/68)
            register s32 t asm("$2") = self->character;
            if (t != 0) {
                self->weapon = 1;
                self->air_action = 6;
            }
        }
        play_sound(1, 1, arg0);
        self->action = 0x1F;
        self->action_phase = 0;
        self->action_timer = 0;
        return 1;
    }
    return 0;
}
