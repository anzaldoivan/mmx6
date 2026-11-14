/* Adapted from sozud/mmx4 @4e16dfc src/main/player.c:player_script_vanish, AGPL-3.0; proven shared with X6 by exact signature 8c272e77d29e (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system player | range 0x80037F70-0x80037FD0
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#include "mmx6/pilot_globals.h"
// 0x80037F70 player_script_vanish: animates the player, then hides it at the last step.
// basis: x4 exact 8c272e77d29e
// callers: none known
void player_script_vanish(struct X4_PlayerObj* self) {
    if (func_8003A628(self) == 0 && self->action_phase == 0) {
        ((void (*)())animate_object)(ANIMATED_OBJECT(self));
        if (self->animation_step.fields.relative_step == 0) {
            self->on_screen = 0;
            self->action_phase++;
        }
    }
}
