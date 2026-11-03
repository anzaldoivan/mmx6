// prog SLUS_013.95 | system movement | range 0x800353C0-0x8003561C
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x800353C0 update_walk_start: walk start: the move checks, then moves while the start animation runs and goes on to walking at its end; stands when check_walk_start_input drops.
// basis: code via=action; derived.tsv:71
// callers: update_player
// dispatch: player_action_handlers[action 3] in update_player
void update_walk_start(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if ((((s32(*)())func_8003A628)() == 0) && (try_enter_ladder(arg0) == 0) &&
        (try_start_attack(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_80039C40(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (check_walk_start_input(arg0) != 0) {
            ((void (*)())animate_object)(arg0);
            if (self->animation_step.fields.relative_step < 0) {
                func_8003AED4(arg0);
                return;
            }
            move_by_velocity(arg0);
            func_8003F508(arg0, 7);
            return;
        }
        func_8003ADB4(arg0);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x800354E8 func_800354E8: walking: the move checks, then moves and animates while check_walk_input holds, else stands (func_8003ADB4).
// basis: none
// callers: update_player
// dispatch: player_action_handlers[action 4] in update_player
void func_800354E8(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if ((((s32(*)())func_8003A628)() == 0) && (try_enter_ladder(arg0) == 0) &&
        (try_start_attack(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (check_ceiling_jump(arg0) == 0) && (func_80039C40(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EBE54(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (check_crouch_input(arg0) == 0)) {
        if (check_walk_input(arg0) != 0) {
            animate_object(arg0);
            move_by_velocity(arg0);
            func_8003F508(arg0, 8);
            return;
        }
        func_8003ADB4(arg0);
    }
}
