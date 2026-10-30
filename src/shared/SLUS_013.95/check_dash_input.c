#include "common.h"
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

// 0x80039EB0 check_dash_input: dash input incl. double tap.
// basis: community tweaks-index.tsv:243
// callers: func_800365D4, func_8003F32C, func_801EC020, player_check_dash_jump_walk
s32 check_dash_input(struct X4_PlayerObj* arg0) {
    if ((M2C_FIELD(arg0, s8*, 0xD3) != 0) ||
        ((arg0->double_tap_dash == 0) && !(arg0->pressed_input & 0x100))) {
        // !FAKE: shares the return-0 block with the flag test in the second arm
        goto ret0;
    }
    if (arg0->input.buttons.held & 1) {
        arg0->unk15 = 0x40;
    }
    if (arg0->input.buttons.held & 2) {
        arg0->unk15 = 0;
    }
    if (arg0->unk15 != 0) {
        if (arg0->unk88.bytes.collision_flags & 1) {
            // !FAKE: shares the return-0 block with the flag test in the second arm
            goto ret0;
        }
        arg0->x_vel.val = M2C_FIELD(arg0, s32*, 0x104);
    } else {
        if (arg0->unk88.bytes.collision_flags & 2) {
        ret0:
            return 0;
        }
        arg0->x_vel.val = -M2C_FIELD(arg0, s32*, 0x104);
    }
    return 1;
}
