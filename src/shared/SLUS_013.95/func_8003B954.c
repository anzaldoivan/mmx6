/* Adapted from sozud/mmx4 @807a01b src/main/player_enter.c:player_enter_beam_out, AGPL-3.0; proven shared with X6 by exact signature f6ae817e5d19 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_80016C48(s32, s32, void*);

void func_8003B954(struct X4_PlayerObj* self) {
    ((s32(*)())func_80016C48)(1, 0xB, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(8);
    self->unk2C = 0;
    self->unk68 = 0;
    self->air_state = 1;
    self->unk5 = PLAYER_BEAM_OUT;
    self->unk6 = 0;
}
