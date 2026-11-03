// prog SLUS_013.95 | system weapon | range 0x8003E174-0x8003E25C
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003E174 try_shoot_in_air: fires a shot and starts the attack pose in the air states.
// basis: xref derived.tsv:131; xref:caller=start_player_attack
// callers: handle_jump_rise, handle_slide_down, update_fall, update_wall_cling, update_wall_jump_push, update_wall_jump_rise, update_slide_down_let_go, rock_00 update_hover
// unnamed callers: func_80037130
s32 try_shoot_in_air(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 t;
    s8 u;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->character != 0) {
        return 0;
    }
    if (check_giga_attack(self) != 0) {
        return 1;
    }
    try_fire_shot(self);
    if (self->shot_fired == 0) {
        return 0;
    }
    t = self->shot_type;
    if (D_80073E00[t] == 0) {
        return 0;
    }
    if (t != 0x32) {
        self->dash_momentum = 0;
    }
    u = self->shot_type;
    self->afterimage = 0;
    if (u == 5 || u == 0xE) {
        if (self->action == 0xB) {
            player_set_animation(self, 0x7F);
        } else {
            player_set_animation(self, 0x7A);
        }
    }
    start_player_attack(self, 1);
    return 1;
}
