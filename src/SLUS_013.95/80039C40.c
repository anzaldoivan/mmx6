// prog SLUS_013.95 | system movement | range 0x80039C40-0x80039DF8
/* Adapted from sozud/mmx4 @29b62af src/main/player_check.c:player_check_dash_jump, AGPL-3.0; proven shared with X6 by exact signature 45aeff6b7124 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 check_dash_input(struct X4_PlayerObj*);

// 0x80039C40 func_80039C40: dash or jump check: a dash input starts a dash, else a JUMP press starts a jump; returns 1 when taken.
// basis: none
// callers: update_stand, update_walk_start
// unnamed callers: func_800354E8, func_80035D38, func_80036800, rock_00 and rock_01 player states
s32 func_80039C40(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (check_dash_input(self) != 0) {
        start_dash(self);
        return 1;
    }
    if (self->pressed_input & PLAYER_INPUT_JUMP) {
        start_jump(self);
        return 1;
    }
    return 0;
}
