/* Adapted from sozud/mmx4 @807a01b src/main/player_special.c:player_hover_set_direction, AGPL-3.0; proven shared with X6 by exact signature 5022eaa90621 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
void player_hover_set_direction(struct X4_PlayerObj* self, s32 direction) {
    if (direction > 0) {
        ((void (*)())player_set_animation_shooting)(self, 0x17);
        self->unk6 = 3;
    } else {
        ((void (*)())player_set_animation_shooting)(self, 0x19);
        self->unk6 = 5;
    }
}
