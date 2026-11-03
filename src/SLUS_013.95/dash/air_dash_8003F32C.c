// prog SLUS_013.95 | system dash | range 0x8003F32C-0x8003F3D8
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

// 0x8003F32C try_start_air_dash: on dash input sets animation 0xBD and state 0x4A, zeroes speeds and spawns the dash effect; returns 1 when taken.
// basis: xref derived.tsv:23
// callers: select_air_dash
s32 try_start_air_dash(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (!(self->pressed_input & 0x80) && check_dash_input(arg0) == 0) {
        return 0;
    }
    player_set_animation(arg0, 0xBD);
    {
        // !FAKE: numeric pin keeps 0xF loaded before the first byte store
        register s32 f asm("$3") = 0xF;
        self->dash_momentum = 1;
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->gravity = 0;
        self->dash_timer = f;
        self->air_action = 7;
    }
    self->is_clone = 0;
    player_clear_attack(arg0);
    self->action = 0x4A;
    self->action_phase = 0;
    player_spawn_weapon(0x21, 0x20, 0, (s32)arg0);
    return 1;
}
