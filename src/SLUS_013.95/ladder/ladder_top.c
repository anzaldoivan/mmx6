// prog SLUS_013.95 | system movement | range 0x8003B6B4-0x8003B704
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

// 0x8003B6B4 reach_ladder_top: enters action 14 phase 1: snaps y to the tile and clears the attack.
// basis: xref derived.tsv:113; xref:callee=try_leave_ladder
// callers: try_leave_ladder
void reach_ladder_top(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    ((void (*)(void*, s32))player_set_animation)(arg0, 0x1C);
    self->terrain_box = 0;
    self->y_pos.i.lo = 0;
    self->y_pos.u.hi = self->y_pos.u.hi & 0xFFF0;
    ((void (*)())player_clear_attack)(arg0);
    self->action = 0xE;
    self->action_phase = 1;
}
