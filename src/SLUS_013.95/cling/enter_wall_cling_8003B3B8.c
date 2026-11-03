// prog SLUS_013.95 | system cling | range 0x8003B3B8-0x8003B43C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/sound.h"

// 0x8003B3B8 player_enter_wall_cling: enters the wall cling: animation 0xD, sound 1/4, motion and gravity zeroed, unk8A 8, faces away from the wall, action 9.
// basis: x4 0d5bb8e12551
// callers: try_enter_wall_cling
void player_enter_wall_cling(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    // !FAKE: flag byte lives in the second return register
    register s32 t asm("$3");

    player_set_animation_shooting(arg0, 0xD);
    play_sound(1, 4, arg0);
    t = self->latched_collision_flags;
    {
        // !FAKE: the -1 constant lives in the first return register
        register s32 m asm("$2") = -1;
        self->afterimage = m;
    }
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->gravity = 0;
    self->dash_momentum = 0;
    self->air_action = 0;
    self->unk8A = 8;
    if (t & 1) {
        self->facing = 0x40;
    } else {
        self->facing = 0;
    }
    self->action = 9;
    self->action_phase = 0;
}
