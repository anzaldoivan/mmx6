// prog SLUS_013.95 | system movement | range 0x800365D4-0x800368F8
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x800365D4 func_800365D4: action 31 phase 3, after perform_ceiling_jump meets a ceiling: dash input goes to phase 4; holds while the ceiling flag stays and DOWN/CROSS are not pressed, counting action_timer down; ends through end_dash.
// basis: none
// callers: none known
// dispatch: ceiling_jump_phase_table[3] in update_ceiling_jump (action 31; table word read from the retail image)
void func_800365D4(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->input.buttons.held & 1) {
        self->facing = 0x40;
    }
    if (self->input.buttons.held & 2) {
        self->facing = 0;
    }
    if (check_dash_input(arg0) != 0) {
        func_8003B298(arg0);
        player_set_animation(arg0, 0x55);
        {
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 a asm("$2") = 0x1F;
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 b asm("$3") = 4;
            self->action = a;
            self->action_phase = b;
        }
        return;
    }
    ((void (*)())animate_object)(arg0);
    if ((self->input.buttons.held & 8) || (self->pressed_input & 0x80) ||
        !(self->latched_collision_flags & 4)) {
        self->action_timer = 0;
    }
    if (self->action_timer != 0) {
        --*(u8*)&self->action_timer;
        if (self->character == 0) {
            func_8003F700(arg0);
        } else if (func_801ECA50(arg0) != 0) {
            return;
        }
    }
    if (self->character == 0) {
        if (self->shot_fired != 0) {
            player_set_animation(arg0, 0x8C);
        }
        if (self->attack_ended != 0) {
            player_set_animation(arg0, 0x54);
        }
    }
    if ((self->action_timer == 0) &&
        (self->animation_step.fields.relative_step == 0)) {
        end_dash((s32)arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

// 0x8003674C update_move_off_screen: phase 0 waits for the animation end and sets animation 4; phase 1 moves until is_off_screen reports the object out of view, then turns it off (state 3).
// basis: code via=is_off_screen; derived.tsv:74
// callers: update_player
// dispatch: player_action_handlers[action 1] in update_player
void update_move_off_screen(struct X4_MainObj* arg0) {
    ((void (*)())animate_object)();
    if (arg0->action_phase == 0) {
        if (arg0->animation_step.fields.relative_step == 0) {
            background_objects[0].unk28 = background_objects[0].y_pos.i.hi;
            background_objects[0].unk2A = background_objects[0].y_pos.i.hi;
            background_objects[0].unk20 = background_objects[0].y_pos.i.hi;
            background_objects[0].unk22 = background_objects[0].y_pos.i.hi;
            ((void (*)(void*, s32))player_set_animation)(arg0, 4);
            arg0->terrain_box = 0;
            arg0->action_phase++;
        }
    } else {
        if (is_off_screen(arg0, 0x20, 0x40) == 0) {
            move_by_velocity(arg0);
            func_8003D394(arg0);
            return;
        }
        arg0->on_screen = 0;
        arg0->state = 3;
        arg0->action = 0;
        arg0->action_phase = 0;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#define M2C_UNK s32

// 0x80036800 func_80036800: the move checks without the attack and ceiling-jump tests; start_walk when check_walk_start_input holds, else ends at the animation end (func_8003AD18).
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 5] in update_player
void func_80036800(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if ((func_8003A628(arg0) == 0) && (try_enter_ladder(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_80039C40(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (check_walk_start_input(arg0) != 0) {
            start_walk(arg0);
            return;
        }
        ((void (*)())animate_object)(arg0);
        if (self->animation_step.fields.relative_step < 0) {
            func_8003AD18(arg0);
        }
    }
}
