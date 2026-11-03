// prog SLUS_013.95 | system cling | range 0x8003A2CC-0x8003A338
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"

// 0x8003A2CC try_enter_wall_cling: enters wall cling when not locked and touching a wall; returns 1 when taken.
// basis: xref derived.tsv:17; xref:caller=player_enter_wall_cling
// callers: handle_jump_rise, player_hover_hold, player_hover_forward, player_hover_forward_stop, player_hover_back, player_hover_back_stop, update_fall, player_hover_idle, update_wall_jump_rise
// unnamed callers: rock_00 func_801EAA38, rock_01 func_801EB324, rock_01 func_801EB5F8, rock_01 func_801EBA7C
s32 try_enter_wall_cling(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (!(self->latched_collision_flags & 3)) {
        return 0;
    }
    if (try_wall_jump(arg0) != 0) {
        return 1;
    }
    if (is_pressing_into_wall(arg0) == 0) {
        return 0;
    }
    player_enter_wall_cling(arg0);
    return 1;
}
