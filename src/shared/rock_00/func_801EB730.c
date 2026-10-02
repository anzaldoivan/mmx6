/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_ladder_shoot, AGPL-3.0; proven shared with X6 by exact signature 543816517dc7 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8003BB94(struct X4_PlayerObj*, s32, s32);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8003E260(struct X4_PlayerObj*);
s32 func_8003A5D8(struct X4_PlayerObj* self);
void func_8003B810(struct X4_PlayerObj* self);

void func_801EB730(struct X4_PlayerObj* self) {
    if ((func_8003A5D8(self) == 0) && (func_8003E260(self) == 0)) {
        func_80017A04(ANIMATED_OBJECT(self));
        if (self->pressed_input & PLAYER_INPUT_LEFT) {
            self->unk15 = 0;
        }
        if (self->pressed_input & PLAYER_INPUT_RIGHT) {
            self->unk15 = 0x40;
        }
        if (self->attack_ended != 0) {
            func_8003BB94(self, 0x20, 3);
            func_8003B810(self);
        }
    }
}
