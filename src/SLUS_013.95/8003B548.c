// prog SLUS_013.95 | system movement | range 0x8003B548-0x8003B638
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/effect.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"

// 0x8003B548 start_slide_down: starts action 11: dust unless armor 2, x speed 0, y speed from slide_down_speed (the slide speed).
// basis: code via=action; derived.tsv:20
// callers: update_wall_cling
void start_slide_down(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    player_set_animation_shooting(arg0, 0xF);
    if (self->armor != 2) {
        spawn_dust(arg0);
    }
    self->air_state = -1;
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->y_vel.val = self->slide_down_speed;
    ((void (*)())player_clear_dash)(arg0);
    self->action = 0xB;
    self->action_phase = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/graphics.h"

// 0x8003B5B8 func_8003B5B8: enters action 11 phase 1: x speed away from the wall, base gravity back on.
// basis: none
// callers: handle_slide_down
// unnamed callers: rock_00 func_801EACA0, rock_01 func_801EC334
s32 func_8003B5B8(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    player_set_animation_shooting(arg0, 0xB);
    if (self->latched_collision_flags & 1) {
        self->x_vel.val = -self->walk_speed;
    } else {
        self->x_vel.val = self->walk_speed;
    }
    self->unk8A = 4;
    self->air_state = -1;
    self->action = 0xB;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->action_phase = 1;
    self->gravity = self->base_gravity;
}
