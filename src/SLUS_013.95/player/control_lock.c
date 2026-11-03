// prog SLUS_013.95 | system player | range 0x80037DC4-0x80037E18
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80037DC4 update_control_lock: control lock: waits and animates while unkD0 is set, then stands (action 2); seen during the opening dialog.
// basis: oracle derived.tsv:88; oracle:docs/systems/movement.md mv_walk-0007 mv_hover2-0009 mv_ceiling2-0009
// callers: update_player
// dispatch: player_action_handlers[action 20] in update_player
void update_control_lock(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    set_pose_size();
    if (func_8003A628(arg0) == 0) {
        if (self->unkD0 == 0) {
            self->action = 2;
            self->action_phase = 0;
            return;
        }
        animate_object(arg0);
    }
}
