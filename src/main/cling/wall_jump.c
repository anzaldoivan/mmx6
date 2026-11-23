#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"

#define M2C_UNK s32

// 0x80036C28 update_wall_jump: jump from a wall: phase 0 runs update_wall_jump_push (push off), later phases update_wall_jump_rise (rise).
// basis: code via=action; derived.tsv:78
// callers: update_player
// dispatch: player_action_handlers[action 10] in update_player
void update_wall_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->action_phase == 0) {
        update_wall_jump_push();
        return;
    }
    update_wall_jump_rise();
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80036C68 update_wall_jump_push: wall jump phase 0: moves away from the wall for unk8A frames, then zeroes x_vel and goes to phase 1; func_8003AFF4 on lock, ceiling or a wall ahead.
// basis: code via=action_phase; derived.tsv:79
// callers: update_wall_jump
void update_wall_jump_push(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_a1;
    s32 var_v0;
    u8 temp_a0;
    u8 temp_v0;
    s32 t4;

    if (self->move_lock != 0) {
        ((void (*)())func_8003AFF4)();
        return;
    }
    if (try_shoot_in_air(arg0) == 0) {
        temp_a0 = self->latched_collision_flags;
        t4 = temp_a0 & 4;
        var_a1 = t4 != 0;
        if (self->facing != 0) {
            var_v0 = temp_a0 & 2;
        } else {
            var_v0 = temp_a0 & 1;
        }
        if (var_v0 != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            func_8003AFF4((s32)arg0);
            return;
        }
        ((void (*)())animate_object)(arg0);
        apply_player_motion(arg0);
        func_8003D394(arg0);
        if (--*(s8*)&self->unk8A == 0) {
            self->x_vel.val = 0;
            self->action_phase = 1 + *(u8*)&self->action_phase;
            return;
        }
        func_8003F508(arg0, 0xE);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"
#include "mmx6/dash.h"
#include "mmx6/graphics.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80036D4C update_wall_jump_rise: wall jump phase 1: rises; y_vel cut on lock, ceiling or CROSS release; air checks; falls (action 7) once y_vel <= 0.
// basis: code via=y_vel; derived.tsv:80
// callers: update_wall_jump
void update_wall_jump_rise(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_v0;

    if (self->move_lock != 0) {
        self->y_vel.val = 0;
    }
    if (self->latched_collision_flags & 4) {
        self->y_vel.val = 0;
    }
    if (!(self->input.buttons.held & 0x80)) {
        self->y_vel.val = 0;
    }
    if (self->character == 0) {
        var_v0 = try_shoot_in_air(arg0);
    } else {
        var_v0 = func_801EBF94(arg0);
    }
    if ((var_v0 == 0) && (try_grab_ladder_from_air(arg0) == 0) &&
        (func_80039984(arg0) == 0) && (try_enter_wall_cling(arg0) == 0) &&
        (select_air_dash(arg0) == 0)) {
        animate_object(arg0);
        set_air_x_velocity(arg0);
        func_8003D394(arg0);
        if (self->y_vel.val <= 0) {
            player_set_animation_shooting(arg0, 0xB);
            self->air_state = -1;
            self->action = 7;
            self->action_phase = 0;
            return;
        }
        func_8003F508(arg0, 0xE);
    }
}
