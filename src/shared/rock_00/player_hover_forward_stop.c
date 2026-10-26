/* Adapted from sozud/mmx4 @807a01b src/main/player_special.c:player_hover_forward_stop, AGPL-3.0; proven shared with X6 by exact signature c351fcf586bf (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_801EC35C();

s32 func_8003A2CC(void*);
#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
s32 func_801EC3AC(void*);
void player_hover_set_direction(struct X4_PlayerObj* self, s32 direction);
void player_hover_forward_stop(struct X4_PlayerObj* self) {
    s32 action;

    if (func_801EC35C(self) == 0 && func_8003A2CC(self) == 0) {
        action = func_801EC3AC(self);
        if (action != PLAYER_BEAM_IN) {
            player_hover_set_direction(self, action);
            return;
        }
        if (self->animation_step.fields.relative_step == 0) {
            ((void (*)())player_set_animation_shooting)(self, 0x16);
            self->unk6 = 2;
            return;
        }
        func_8003F508(self, 0x18);
    }
}
