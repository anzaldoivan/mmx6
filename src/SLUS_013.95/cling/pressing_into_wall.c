// prog SLUS_013.95 | system cling | range 0x8003A394-0x8003A3D8
#include "common.h"
#include "mmx6/x4.h"

// 0x8003A394 is_pressing_into_wall: returns 1 when L/R is held into a touching climbable wall.
// basis: xref derived.tsv:101; xref:callee=try_enter_wall_cling
// callers: handle_slide_down, try_enter_wall_cling
s32 is_pressing_into_wall(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->wall_climbable == 0) {
        return 0;
    }
    return (self->input.buttons.held & 3 & self->latched_collision_flags) != 0;
}
