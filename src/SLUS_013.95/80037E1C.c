// prog SLUS_013.95 | system movement | range 0x80037E1C-0x80037F6C
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/pilot_globals.h"
#define M2C_UNK s32

// 0x80037E1C func_80037E1C: phase 0 animates until D_800CCEDF is set; phase 1 turns the object off (state 3).
// basis: none
// callers: none known
void func_80037E1C(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->action_phase == 0) {
        ((void (*)())animate_object)();
        if (D_800CCEDF != 0) {
            self->action_phase = 1 + *(u8*)&self->action_phase;
        }
    } else {
        self->state = 3;
        self->action = 0;
        self->action_phase = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

// 0x80037E88 func_80037E88: D_800CCEDF set leads to func_8003B870; else x_vel from walk_start_speed/walk_speed by the animation event, signed by facing; moves, animates, func_8003A678 when unkD2 is 0.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 21] in update_player
void func_80037E88(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (D_800CCEDF != 0) {
        func_8003B870(arg0);
        return;
    }
    if (self->animation_step.fields.event == 0) {
        self->x_vel.val = self->walk_start_speed;
    } else {
        self->x_vel.val = self->walk_speed;
    }
    if (self->facing == 0) {
        self->x_vel.val = -self->x_vel.val;
    }
    move_by_velocity(arg0);
    ((void (*)(void*))animate_object)(arg0);
    if (self->unkD2 == 0) {
        func_8003A678(arg0);
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/player_special.c:player_zero_ryuenjin_rise, AGPL-3.0; proven shared with X6 by exact signature dff51a405822 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"

// 0x80037F34 func_80037F34: unless func_8003A628 takes over, moves and animates.
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 29] in update_player
void func_80037F34(struct X4_PlayerObj* self) {
    if (func_8003A628(self) == 0) {
        move_by_velocity(self);
        animate_object(self);
    }
}
