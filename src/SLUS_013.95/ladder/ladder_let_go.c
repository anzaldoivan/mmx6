/* Adapted from sozud/mmx4 @4e16dfc src/main/player.c:player_ladder_let_go, AGPL-3.0; proven shared with X6 by exact signature 97ce869b32ad (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system ladder | range 0x800377FC-0x80037834
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32
// 0x800377FC player_ladder_let_go: action 14 phase 4: animates, then func_8003AFF4 at the animation end.
// basis: x4 97ce869b32ad
// callers: none known
// dispatch: D_80073C1C[4] in func_8003744C (action 14)
void player_ladder_let_go(struct X4_PlayerObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.relative_step < 0) {
        func_8003AFF4(self);
    }
}
