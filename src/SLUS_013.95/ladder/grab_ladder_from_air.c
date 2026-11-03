// prog SLUS_013.95 | system ladder | range 0x8003A488-0x8003A510
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x8003A488 try_grab_ladder_from_air: UP held over tile 0x20 at the origin grabs the ladder (animation 0x1F and player_enter_ladder_climb_up, or func_801EB6E8 when attacking); returns 1.
// basis: code via=attacking; derived.tsv:102
// callers: handle_jump_rise
s32 try_grab_ladder_from_air(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if (self->move_lock != 0) {
        return 0;
    }
    if (!(self->input.buttons.held & 4)) {
        return 0;
    }
    if (get_tile_attr_origin(arg0) != 0x20) {
        return 0;
    }
    if (self->attacking == 0) {
        player_set_animation(arg0, 0x1F);
        player_enter_ladder_climb_up(arg0);
        return 1;
    }
    func_801EB6E8(arg0);
    return 1;
}
