/* Adapted from sozud/mmx4 @807a01b src/main/player_special.c:player_ladder_shoot, AGPL-3.0; proven shared with X6 by exact signature 543816517dc7 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void player_set_animation_frame(struct X4_PlayerObj*, s32, s32);
void animate_object(struct X4_AnimatedObj*);
s32 try_shoot_on_ladder(struct X4_PlayerObj*);
s32 func_8003A5D8(struct X4_PlayerObj* self);
void player_enter_ladder_climb_down(struct X4_PlayerObj* self);

void player_ladder_shoot(struct X4_PlayerObj* self) {
    if ((func_8003A5D8(self) == 0) && (try_shoot_on_ladder(self) == 0)) {
        animate_object(ANIMATED_OBJECT(self));
        if (self->pressed_input & PLAYER_INPUT_LEFT) {
            self->facing = 0;
        }
        if (self->pressed_input & PLAYER_INPUT_RIGHT) {
            self->facing = PLAYER_FACING_RIGHT;
        }
        if (self->attack_ended != 0) {
            player_set_animation_frame(self, 0x20, 3);
            player_enter_ladder_climb_down(self);
        }
    }
}
