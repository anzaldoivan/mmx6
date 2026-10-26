/* Adapted from sozud/mmx4 @807a01b src/main/player.c:player_script_vanish, AGPL-3.0; proven shared with X6 by exact signature 8c272e77d29e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04(void*);
void player_script_vanish(struct X4_PlayerObj* self) {
    if (func_8003A628(self) == 0 && self->unk6 == 0) {
        ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
        if (self->animation_step.fields.relative_step == 0) {
            self->on_screen = 0;
            self->unk6++;
        }
    }
}
