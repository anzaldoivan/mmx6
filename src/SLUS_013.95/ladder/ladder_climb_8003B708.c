// prog SLUS_013.95 | system ladder | range 0x8003B708-0x8003B770
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

// 0x8003B708 player_enter_ladder_climb_on_top: starts climbing down onto a ladder from its top: animation 0x1D, x snapped to the tile centre, action 14 phase 2.
// basis: x4 2d72789ebd19
// callers: try_enter_ladder
void player_enter_ladder_climb_on_top(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    ((void (*)(void*, s32))player_set_animation)(arg0, 0x1D);
    self->x_pos.i.lo = 0;
    self->y_pos.i.lo = 0;
    self->terrain_box = 0;
    self->air_state = 1;
    self->x_pos.u.hi = (self->x_pos.u.hi & 0xFFF0) + 8;
    ((void (*)())player_clear_dash)(arg0);
    ((void (*)())player_clear_attack)(arg0);
    self->action = 0xE;
    self->action_phase = 2;
}
