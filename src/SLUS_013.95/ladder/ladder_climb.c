/* Adapted from sozud/mmx4 @807a01b src/main/player.c:player_ladder_climb_on_top, AGPL-3.0; proven shared with X6 by exact signature 78487e2d128b (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system ladder | range 0x80037548-0x800375CC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#define M2C_UNK s32

// 0x80037548 player_ladder_climb_on_top: action 14 phase 2: animates the move between ladder top and tile; at its end shifts y 16 px and enters the climb-down state (player_enter_ladder_climb_down).
// basis: x4 78487e2d128b
// callers: none known
// dispatch: D_80073C1C[2] in func_8003744C (action 14)
void player_ladder_climb_on_top(struct X4_PlayerObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.event & 0x80) {
        self->animation_step.fields.event = 0;
        self->y_pos.i.hi = (self->y_pos.u.hi & 0xFFF0) + 0x20;
    }
    if (self->animation_step.fields.relative_step < 0) {
        self->y_pos.i.hi = self->y_pos.u.hi + 0x10;
        ((void (*)())set_pose_size)(self);
        ((void (*)())player_set_animation_frame)(self, 0x20, 3);
        player_enter_ladder_climb_down(self);
    }
}
