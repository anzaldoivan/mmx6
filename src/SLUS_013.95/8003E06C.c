// prog SLUS_013.95 | system movement | range 0x8003E06C-0x8003E170
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003E06C func_8003E06C: fires a shot and starts the attack pose, for two unnamed ground states.
// basis: none
// callers: none known
// unnamed callers: func_8003605C, func_800361D4
s32 func_8003E06C(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 k;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->character != 0) {
        return 0;
    }
    if (check_giga_attack(arg0) != 0) {
        return 1;
    }
    try_fire_shot(arg0);
    if (self->shot_fired == 0) {
        return 0;
    }
    k = self->shot_type;
    if (D_80073E00[k] == 0) {
        return 0;
    }
    self->dash_momentum = 0;
    self->air_action = 0;
    self->afterimage = 0;
    if (k == 5 || k == 14) {
        if (self->action == 0x1B) {
            player_set_animation(arg0, 0x91);
        } else {
            player_set_animation(arg0, 0x97);
        }
        start_player_attack(arg0, 1);
    } else if (k == 50) {
        ((void (*)(void*))func_8003AFF4)(arg0);
        start_player_attack(arg0, 1);
    } else {
        ((void (*)(void*, s32))start_player_attack)(arg0, 0);
    }
    return 1;
}
