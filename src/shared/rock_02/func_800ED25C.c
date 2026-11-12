/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_48_sentry_drone.c:sentry_drone_drift_move, AGPL-3.0; proven shared with X6 by exact signature a6e79c949180 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800ED25C(struct X4_MainObj* self) {
    s8 timer;
    animate_object(ANIMATED_OBJECT(self));
    move_object(MOVING_OBJECT(self));
    timer = --SP_CUR_MAIN_OBJ->ext.main_48.unk80;
    if (timer == 0) {
        self->action = 3;
        self->action_phase = 0;
    }
}
