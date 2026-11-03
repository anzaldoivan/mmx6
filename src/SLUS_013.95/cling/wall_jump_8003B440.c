// prog SLUS_013.95 | system cling | range 0x8003B440-0x8003B544
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"

// 0x8003B440 start_wall_jump: starts action 10: faces and pushes x away from the wall, dash speed if CIRCLE held, sets the rise speed.
// basis: code code:src/SLUS_013.95/cling/wall_jump_8003B440.c:52 via=action; glossary.md:425
// callers: try_wall_jump
void start_wall_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    player_set_animation_shooting(arg0, 0xE);
    play_sound(1, 3, arg0);
    play_sound_unless_low_health(arg0, 2);
    {
        s32 one = 1;
        // !FAKE: depin: dropping it breaks the match (58/66)
        register s32 t asm("$2");
        self->air_state = one;
        t = self->input.buttons.held & 0x100;
        if (t) {
            self->dash_momentum = one;
            self->air_action = one;
            self->afterimage = one;
        } else {
            player_clear_dash(arg0);
        }
    }
    if (self->latched_collision_flags & 1) {
        self->facing = 0x40;
        if (self->dash_momentum != 0) {
            self->x_vel.val = -self->dash_base_speed;
        } else {
            self->x_vel.val = -self->walk_speed;
        }
    } else {
        self->facing = 0;
        if (self->dash_momentum != 0) {
            self->x_vel.val = self->dash_base_speed;
        } else {
            self->x_vel.val = self->walk_speed;
        }
    }
    self->x_accel = 0;
    self->unk8A = 0xA;
    self->y_vel.val = self->wall_jump_y_speed;
    self->gravity = self->jump_gravity;
    spawn_wall_jump_visual(arg0);
    self->action = 0xA;
    self->action_phase = 0;
}
