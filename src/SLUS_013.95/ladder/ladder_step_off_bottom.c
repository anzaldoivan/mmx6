/* Adapted from sozud/mmx4 @807a01b src/main/player.c:player_ladder_step_off_bottom, AGPL-3.0; proven shared with X6 by exact signature 26cbae375ca4 (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system ladder | range 0x800375D0-0x8003760C
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32
// 0x800375D0 player_ladder_step_off_bottom: action 14 phase 3: animates, then stands (func_8003ADB4) on the ground at the animation end.
// basis: x4 26cbae375ca4
// callers: none known
// dispatch: D_80073C1C[3] in func_8003744C (action 14)
void player_ladder_step_off_bottom(struct X4_PlayerObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.relative_step < 0) {
        self->air_state = 0;
        func_8003ADB4(self);
    }
}
