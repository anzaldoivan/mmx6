// prog SLUS_013.95 | system movement | range 0x80037130-0x80037378
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80037130 func_80037130: lands on the floor flag, func_8003AFF4 on lock; tries func_80039984 and the ladder; X attacking goes to func_8003B360; else animates and runs D_80073C10[action_phase].
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 13] in update_player
void func_80037130(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->latched_collision_flags & 8) {
        ((void (*)())player_land)();
        return;
    }
    if (self->move_lock != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (func_80039984(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (self->character == 0) {
        if (try_shoot_in_air(arg0) != 0) {
            return;
        }
        if (self->attacking != 0) {
            func_8003B360(arg0);
            return;
        }
    }
    animate_object(arg0);
    (*(void (**)(void*))((self->action_phase << 2) + (s32)D_80073C10))(arg0);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"

#define M2C_UNK s32

// 0x80037220 func_80037220: action 13 phase 0: stops all motion when func_801EC028 holds (not X); animation event 0x40 runs func_8003D26C, event 0x80 plays sound 1/5, sets afterimage and goes to phase 1.
// basis: none
// callers: none known
// dispatch: D_80073C10[0] in func_80037130
void func_80037220(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 temp_v1;

    if ((self->character != 0) && (func_801EC028() != 0)) {
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->air_state = -1;
        self->dash_momentum = 0;
        self->gravity = (s32)self->base_gravity;
        return;
    }
    temp_v1 = *(u8*)&self->animation_step.fields.event;
    if (temp_v1 & 0x40) {
        self->animation_step.fields.event = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
    if ((s8) * (u8*)&self->animation_step.fields.event & 0x80) {
        self->animation_step.fields.event =
            (u8)(*(u8*)&self->animation_step.fields.event & 0x3F);
        play_sound(1, 5, arg0);
        self->afterimage = 1;
        self->action_phase = (u8)(1 + *(u8*)&self->action_phase);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"

#define M2C_UNK s32

// 0x800372DC func_800372DC: action 13 phase 1: stops all motion when func_801EC028 holds (not X); check_dash_end leads to func_8003B30C; animation event 0x40 runs func_8003D26C.
// basis: none
// callers: none known
// dispatch: D_80073C10[1] in func_80037130
void func_800372DC(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 temp_v1;

    if ((self->character != 0) && (func_801EC028() != 0)) {
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->air_state = -1;
        self->dash_momentum = 0;
        self->gravity = (s32)self->base_gravity;
        return;
    }
    if (check_dash_end(arg0) != 0) {
        func_8003B30C(arg0);
        return;
    }
    temp_v1 = *(u8*)&self->animation_step.fields.event;
    if (temp_v1 & 0x40) {
        self->animation_step.fields.event = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
}
