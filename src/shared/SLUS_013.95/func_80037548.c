/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_ladder_climb_on_top, AGPL-3.0; proven shared with X6 by exact signature 78487e2d128b (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);

M2C_UNK func_80017A04();
M2C_UNK func_8003CCBC();
void func_80037548(struct X4_PlayerObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.event & 0x80) {
        self->animation_step.fields.event = 0;
        self->y_pos.i.hi = (self->y_pos.u.hi & 0xFFF0) + 0x20;
    }
    if (self->animation_step.fields.relative_step < 0) {
        self->y_pos.i.hi = self->y_pos.u.hi + 0x10;
        ((void (*)())func_8003CCBC)(self);
        func_8003BB94(self, 0x20, 3);
        func_8003B810(self);
    }
}
