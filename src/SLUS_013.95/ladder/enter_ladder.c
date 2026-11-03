// prog SLUS_013.95 | system ladder | range 0x8003A3DC-0x8003A484
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/ladder.h"

// 0x8003A3DC try_enter_ladder: grabs a ladder (input bit 4 over tile 0x20) or climbs on top (bit 8 over tile 0x21); returns 1 when taken.
// basis: xref derived.tsv:18; xref:caller=player_enter_ladder_climb_on_top
// callers: update_stand, update_landing, update_air_dash, update_walk_start
// unnamed callers: func_800354E8, func_80035A2C, func_80036800, func_80037130, rock_01 func_801EBC60, rock_01 func_801ECE08
s32 try_enter_ladder(void* arg0) {
    struct X4_PlayerObj* p = arg0;

    if (p->move_lock != 0) {
        return 0;
    }
    if (p->shot_cooldown != 0) {
        return 0;
    }
    if ((p->input.buttons.held & 4) && get_tile_attr_top(p) == 0x20) {
        grab_ladder(p);
        return 1;
    }
    if (!(p->input.buttons.held & 8)) {
        return 0;
    }
    if (get_tile_attr_below(p) != 0x21) {
        return 0;
    }
    player_enter_ladder_climb_on_top(p);
    return 1;
}
