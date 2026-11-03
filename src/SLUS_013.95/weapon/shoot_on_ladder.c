// prog SLUS_013.95 | system weapon | range 0x8003E260-0x8003E340
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x8003E260 try_shoot_on_ladder: fires a shot from the ladder, or enters the ladder shot state.
// basis: xref derived.tsv:132; xref:caller=start_player_attack
// callers: player_ladder_shoot, update_ladder_climb_up, update_ladder_climb_down
s32 try_shoot_on_ladder(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 idx;

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
    idx = self->shot_type;
    if (D_80073E00[idx] == 0) {
        func_801EB6E8(arg0);
        return 1;
    }
    self->afterimage = 0;
    if (idx == 50) {
        func_8003AFF4((s32)arg0);
    } else if (idx == 5 || idx == 14) {
        player_set_animation(arg0, 0x5C);
    }
    start_player_attack(arg0, 1);
    return 1;
}
