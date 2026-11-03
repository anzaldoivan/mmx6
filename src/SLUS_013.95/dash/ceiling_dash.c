// prog SLUS_013.95 | system dash | range 0x8003737C-0x80037448
#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

// 0x8003737C end_ceiling_dash: end of ceiling dash.
// basis: community tweaks-index.tsv:195
// callers: none known
void end_ceiling_dash(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    if (self->latched_collision_flags & 8) {
        ((void (*)())player_land)();
        return;
    }
    if ((self->character != 0) && (func_801EC028(arg0) != 0)) {
        self->x_vel.val = 0;
        self->x_accel = 0;
        self->y_vel.val = 0;
        self->air_state = -1;
        self->dash_momentum = 0;
        self->gravity = self->base_gravity;
        return;
    }
    apply_player_motion(arg0);
    func_8003D394(arg0);
    if ((self->animation_step.fields.relative_step < 0) ||
        (self->input.buttons.held & 3)) {
        ((void (*)(void*, s32))player_set_animation)(arg0, 0x14);
        self->action = 7;
        self->action_phase = 0;
    }
}
