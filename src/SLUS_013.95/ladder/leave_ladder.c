// prog SLUS_013.95 | system ladder | range 0x8003A514-0x8003A5D4
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003A514 try_leave_ladder: while climbing: steps off at the floor, tops out on tile 0x21, or falls when off the ladder tiles or on a button.
// basis: xref derived.tsv:19; xref:caller=player_enter_ladder_step_off_bottom
// callers: update_ladder_climb_up, update_ladder_climb_down
s32 try_leave_ladder(struct X4_PlayerObj* arg0) {
    s32 v;
    s32 t;

    v = get_tile_attr_origin(arg0);
    if (arg0->latched_collision_flags & 8) {
        player_enter_ladder_step_off_bottom(arg0);
        return 1;
    }
    if ((arg0->input.buttons.held & 4) && v == 0x21) {
        reach_ladder_top(arg0);
        return 1;
    }
    t = (u8)(v - 0x20) >= 2;
    if (arg0->pressed_input & 0x80) {
        t = 1;
    }
    if (t != 0) {
        player_set_animation(arg0, 0x1E);
        arg0->action = 0xE;
        arg0->action_phase = 4;
        return 1;
    }
    return 0;
}
