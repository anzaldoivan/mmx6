/* Adapted from sozud/mmx4 @807a01b src/main/player.c:player_ladder_let_go, AGPL-3.0; proven shared with X6 by exact signature 97ce869b32ad (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04(void*);
void player_ladder_let_go(struct X4_PlayerObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.relative_step < 0) {
        func_8003AFF4(self);
    }
}
