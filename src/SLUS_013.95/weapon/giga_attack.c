#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/effect.h"
#include "mmx6/weapon.h"
#define func_8003CDF0 func_8003CDF0

// 0x8003E344 check_giga_attack: giga attack input, armor checks, execution.
// basis: community tweaks-index.tsv:202
// callers: func_8003E06C, try_shoot_in_air, try_shoot_on_ladder, try_start_attack and others
s32 check_giga_attack(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 ret;
    s32 m;
    s32 v;
    u8 k;

    ret = 0;
    if (self->character != 0) {
        return ret;
    }
    if (self->shot_cooldown != 0) {
        return ret;
    }
    if (*(s16*)self->weapon_energy != self->giga_energy_max) {
        return ret;
    }
    if (!(self->pressed_input & 0x40)) {
        return ret;
    }
    k = self->armor;
    if ((u32)(k - 1) >= 4) {
        return 0;
    }
    if (k == 4) {
        if (self->air_action != 0) {
            return 0;
        }
        m = 2;
        if (self->facing != 0) {
            m = 1;
        }
        if (self->latched_collision_flags & m) {
            return 0;
        }
    }
    func_8003CDF0(self);
    if (self->character == 0) {
        self->weapon = 0;
        player_reset_charge(self);
        set_shot_types(self);
        react_to_weapon_change(self);
    }
    self->air_state = 1;
    self->invincibility_timer = 0;
    self->hurt_phase = 0;
    if (self->armor != 4) {
        *(s16*)self->weapon_energy = 0;
    }
    k = self->armor;
    if (k == 1) {
        if (self->latched_collision_flags & 8) {
            player_set_animation(self, 0xAE);
        } else {
            player_set_animation(self, 0xB1);
        }
        self->action = 0x24;
        player_spawn_visual(1, 0x1B, 8, 0);
        self->air_action = 5;
        self->nova_strike_timer = 0;
        self->terrain_box = 0;
        self->nova_strike_active = 2;
        ret = 1;
    } else if (k == 2) {
        if (self->latched_collision_flags & 8) {
            player_set_animation(self, 0xB9);
            self->action_timer = 0;
        } else {
            player_set_animation(self, 0xBA);
            self->action_timer = 1;
        }
        self->action = 0x25;
        self->air_action = 5;
        self->nova_strike_timer = 0;
        self->terrain_box = 0;
        self->nova_strike_active = 2;
        player_spawn_visual(1, 0x1B, 7, 0);
        ret = 1;
    } else if (k == 3) {
        if (self->latched_collision_flags & 8) {
            player_set_animation(self, 0xB9);
            self->action_timer = 0;
        } else {
            player_set_animation(self, 0xBA);
            self->action_timer = 1;
        }
        self->action = 0x4D;
        self->air_action = 5;
        self->nova_strike_timer = 0;
        self->terrain_box = 0;
        self->nova_strike_active = 2;
        ret = 1;
    } else {
        player_set_animation(self, 0x6A);
        {
            // !FAKE: depin: dropping it breaks the match (143/180)
            register s32 c asm("$2");
            c = 0x22;
            self->action = c;
            c = 5;
            self->air_action = c;
            c = 0x18;
            self->dash_momentum = 0;
            self->afterimage = 0;
            self->nova_strike_timer = c;
        }
        if (self->facing != 0) {
            self->x_vel.val = 0x28000;
        } else {
            self->x_vel.val = -0x28000;
        }
        self->y_vel.val = 0x38000;
        self->x_accel = 0;
        ret = 1;
        self->nova_strike_active = ret;
        self->action_timer = 0;
        self->gravity = self->base_gravity;
    }
    self->spike_immune = 1;
    D_800CCEEC = 1;
    self->action_phase = 0;
    return ret;
}
