/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_48_sentry_drone.c:sentry_drone_drift_start, AGPL-3.0; proven shared with X6 by exact signature 85e8100d5593 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_800179A4(void*, s32);

void func_800ED1F8(struct X4_MainObj* self) {
    self->air_state = 1;
    self->unk6++;
    self->x_speed = self->unk15 != 0 ? FIXED(0.5) : -FIXED(0.5);
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    SP_CUR_MAIN_OBJ->ext.main_48.unk80 = 0x30;
    func_800179A4(self, 0);
}
