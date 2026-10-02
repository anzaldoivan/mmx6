/* Adapted from sozud/mmx4 @29b62af src/main/player_check.c:player_check_dash_jump_walk, AGPL-3.0; proven shared with X6 by exact signature 67a670686326 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 func_80039EB0(struct X4_PlayerObj*);
M2C_UNK func_8003AF1C(void*);
void func_8003A9C4(struct X4_PlayerObj*);

s32 func_80039BC4(struct X4_PlayerObj* self) {
    if (func_80039EB0(self) != 0) {
        func_8003A9C4(self);
        return 1;
    }
    if ((self->pressed_input & PLAYER_INPUT_JUMP) != 0) {
        func_8003AF1C(self);
        return 1;
    }
    if (func_80039D7C(self) == 0) {
        return 0;
    }
    func_8003AED4(self);
    return 1;
}
