// prog SLUS_013.95 | system cling | range 0x8003A33C-0x8003A390
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"

// 0x8003A33C try_wall_jump: on a climbable wall with CROSS pressed, calls start_wall_jump (the wall jump); returns 1 when taken.
// basis: code via=wall_climbable; derived.tsv:100
// callers: handle_slide_down, try_enter_wall_cling
s32 try_wall_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (!(self->pressed_input & 0x80)) {
        return 0;
    }
    if (self->wall_climbable <= 0) {
        return 0;
    }
    start_wall_jump(arg0);
    return 1;
}
