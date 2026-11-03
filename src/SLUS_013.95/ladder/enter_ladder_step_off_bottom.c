// prog SLUS_013.95 | system ladder | range 0x8003B774-0x8003B7B0
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003B774 player_enter_ladder_step_off_bottom: starts stepping off the ladder bottom: animation 0x1E, action 14 phase 3.
// basis: x4 625cccce011c
// callers: try_leave_ladder
void player_enter_ladder_step_off_bottom(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    player_set_animation(arg0, 0x1E);
    ((void (*)())player_clear_attack)(arg0);
    self->action = 0xE;
    self->action_phase = 3;
}
