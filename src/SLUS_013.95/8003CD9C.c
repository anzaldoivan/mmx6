#include "common.h"
#include "mmx6/x4.h"

void player_clear_dash(struct X4_PlayerObj* self) {
    self->dash_momentum = 0;
    self->air_action = 0;
    if (self->afterimage > 0) {
        self->afterimage = -1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void player_load_weapon_palette(struct X4_PlayerObj* self);

void player_clear_attack(struct X4_PlayerObj* self) {
    self->attacking = 0;
    self->shot_fired = 0;
    self->attack_ended = 0;
    self->attack_pose_timer = 0;
    self->shot_cooldown = 0;
    self->shot_palette_timer = 0;
    player_load_weapon_palette(self);
}

#include "common.h"
#include "mmx6/x4.h"

void player_load_weapon_palette(struct X4_PlayerObj* self);

void func_8003CDF0(struct X4_PlayerObj* self) {
    self->dash_momentum = 0;
    self->air_action = 0;
    self->afterimage = 0;
    self->attacking = 0;
    self->shot_fired = 0;
    self->attack_ended = 0;
    self->attack_pose_timer = 0;
    self->shot_cooldown = 0;
    self->shot_palette_timer = 0;
    player_load_weapon_palette(self);
}
