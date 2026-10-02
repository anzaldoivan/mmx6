/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_07_water_wake.c:water_wake_player_moving, AGPL-3.0; proven shared with X6 by exact signature 98768ef976bc (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800F53E0[9][16];
extern u8 D_800F5470[9][16];

s32 func_800E9D20(struct X4_PlayerObj* arg0) {
    u8 state;

    if (arg0->unk2 == 0) {
        state = D_800F53E0[0][arg0->unk17];
    } else {
        state = D_800F5470[0][arg0->unk17];
    }

    return state == 2;
}
