// prog SLUS_013.95 | system player | range 0x80035274-0x800353BC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"
#include "mmx6/ladder.h"
#include "mmx6/movement.h"

#define M2C_UNK s32

// 0x80035274 update_stand: standing: runs the move checks in order (ladder, attack, ceiling jump, walk, dash); with none taken, plays the idle animation.
// basis: oracle derived.tsv:70; oracle:docs/systems/movement.md mv_walk-0008 mv_walk-0023 mv_jump-0038
// callers: update_player
// dispatch: player_action_handlers[action 2] in update_player
void update_stand(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    set_pose_size();
    if ((func_8003A628(arg0) == 0) && (try_enter_ladder(arg0) == 0) &&
        (try_start_attack(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (check_ceiling_jump(arg0) == 0) && (func_80039C40(arg0) == 0) &&
        ((self->character == 0) ||
         ((func_801EBE54(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (check_crouch_input(arg0) == 0)) {
        if (check_walk_start_input(arg0) != 0) {
            start_walk(arg0);
            return;
        }
        if (self->character == 0) {
            func_801EB61C(arg0);
            return;
        }
        func_801EC9C4(arg0);
    }
}
