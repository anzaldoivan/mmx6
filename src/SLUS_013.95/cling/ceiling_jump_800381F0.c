// prog SLUS_013.95 | system cling | range 0x800381F0-0x800382C4
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"

#define M2C_UNK s32

// 0x800381F0 update_ceiling_jump: action 31 handler, the ceiling jump: falls through func_8003AFF4 under move_lock, else runs ceiling_jump_phase_table[action_phase].
// basis: oracle derived.tsv:89; oracle:docs/systems/movement.md mv_ceiling2-0023 mv_ceiling2-0024 mv_ceiling2-0027
// callers: update_player
// dispatch: player_action_handlers[action 31] in update_player
void update_ceiling_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->move_lock != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    ceiling_jump_phase_table[self->action_phase](arg0);
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

#include "mmx6/state.h"
#include "mmx6/pilot_globals.h"

// 0x80038248 end_ceiling_jump: ceiling_jump_phase_table[1] (action 31 phase 1): animates every other frame, counts action_timer down, then zeroes speed and falls (action 7).
// basis: code via=base_gravity; derived.tsv:90
// callers: none known
void end_ceiling_jump(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (D_80097420.frame_counter & 1) {
        ((M2C_UNK(*)())animate_object)();
    }
    if ((self->action_timer == 0) || (--self->action_timer == 0)) {
        self->air_state = -1;
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->action = 7;
        self->action_phase = 0;
        self->gravity = self->base_gravity;
    }
}
