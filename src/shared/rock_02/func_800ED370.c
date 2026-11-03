/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_48_sentry_drone.c:sentry_drone_dash_move, AGPL-3.0; proven shared with X6 by exact signature 0de043eb0114 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800ED370(struct X4_MainObj* self) {
    s8 timer;
    animate_object(ANIMATED_OBJECT(self));
    move_object(MOVING_OBJECT(self));
    timer = --SP_CUR_MAIN_OBJ->ext.main_48.unk80;
    if (timer == 0) {
        self->air_state = -1;
        self->action = 6;
        self->action_phase = 0;
    }
}
