/* Adapted from sozud/mmx4 @807a01b src/main/player.c:player_ladder_step_off_bottom, AGPL-3.0; proven shared with X6 by exact signature 26cbae375ca4 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04();
void func_8003ADB4(void* arg0);
void player_ladder_step_off_bottom(struct X4_PlayerObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.relative_step < 0) {
        self->air_state = 0;
        func_8003ADB4(self);
    }
}
