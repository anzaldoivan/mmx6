// prog SLUS_013.95 | system player | range 0x80036A04-0x80036B0C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/cling.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

// 0x80036A04 update_landing: landing: the move checks, then the landing animation; stands (func_8003ADB4) at its end.
// basis: oracle derived.tsv:76; oracle:docs/systems/movement.md mv_jump-0035 mv_jump-0042 mv_dash-0049
// callers: update_player
// dispatch: player_action_handlers[action 8] in update_player
void update_landing(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    if ((func_8003A628(arg0) == 0) && (try_enter_ladder(arg0) == 0) &&
        (check_ceiling_jump(arg0) == 0) && (try_start_attack(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EBE04(arg0) == 0))) &&
        (player_check_dash_jump_walk(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0))) &&
        (check_crouch_input(arg0) == 0)) {
        ((void (*)())animate_object)(arg0);
        if (self->animation_step.fields.relative_step < 0) {
            func_8003ADB4(arg0);
            return;
        }
        func_8003F508(arg0, 0xC);
    }
}
