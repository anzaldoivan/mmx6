/* Adapted from sozud/mmx4 @807a01b src/main/player_weapon.c:player_set_animation_shooting, AGPL-3.0; proven shared with X6 by exact signature b7ee5de16676 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK player_set_animation(void*, M2C_UNK);

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation) {
    if (self->character == 0 && self->attacking != 0) {
        animation += 0x70;
    }
    player_set_animation(self, animation);
}
