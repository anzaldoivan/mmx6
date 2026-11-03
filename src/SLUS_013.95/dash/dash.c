// prog SLUS_013.95 | system dash | range 0x800370B0-0x8003712C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

// 0x800370B0 update_dash: ground dash: unless func_8003A628, animates and runs dash_phase_table[action_phase]; set_pose_size when the action changed and a terrain box is set.
// basis: oracle derived.tsv:82; oracle:docs/systems/movement.md mv_dash-0021 mv_dash-0023 mv_dash-0024
// callers: update_player
// dispatch: player_action_handlers[action 12] in update_player
void update_dash(struct X4_MainObj* self) {
    if (func_8003A628(self) == 0) {
        ((void (*)())animate_object)(self);
        dash_phase_table[self->action_phase](self);
    }
    if (self->action != 0xC && self->terrain_box != 0) {
        ((void (*)())set_pose_size)(self);
    }
}
