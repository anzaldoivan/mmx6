/* Adapted from sozud/mmx4 @4e16dfc src/main/player_check.c:player_check_dash_jump_walk, AGPL-3.0; proven shared with X6 by exact signature 67a670686326 (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system player | range 0x80039BC4-0x80039C3C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/dash.h"

// 0x80039BC4 player_check_dash_jump_walk: starts a dash, jump or walk from the input.
// basis: x4 exact 67a670686326
// callers: update_landing, player_land
// unnamed callers: rock_01 func_801EACAC
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self) {
    if (check_dash_input(self) != 0) {
        start_dash(self);
        return 1;
    }
    if ((self->pressed_input & PLAYER_INPUT_JUMP) != 0) {
        start_jump(self);
        return 1;
    }
    if (check_walk_input(self) != 0) {
        func_8003AED4(self);
        return 1;
    }
    return 0;
}
