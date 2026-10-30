/* Adapted from sozud/mmx4 @807a01b src/main/player_common.c:player_entry_beam_in, AGPL-3.0; proven shared with X6 by exact signature 6b996a39570c (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 play_sound(s32, s32, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_8003D850(struct X4_PlayerObj* self) {
    func_8003BA04(self, 1);
    ((s32(*)())play_sound)(1, 0xD, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(-8);
    self->unk2C = 0;
    self->air_state = -1;
    self->unk5 = PLAYER_BEAM_IN;
}
