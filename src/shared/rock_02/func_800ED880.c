/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_48_sentry_drone.c:sentry_drone_drop_start, AGPL-3.0; proven shared with X6 by exact signature 0565770c6716 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_800179A4(void*, s32);

void func_800ED880(struct X4_MainObj* self) {
    self->unk6++;
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = FIXED(2);
    self->gravity = 0;
    func_800179A4(self, 1);
}
