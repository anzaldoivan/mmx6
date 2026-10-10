/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_48_sentry_drone.c:sentry_drone_dash_start, AGPL-3.0; proven shared with X6 by exact signature 327f58c0753a (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_800179A4(void*, s32);

void func_800ED2F4(struct X4_MainObj* self) {
    s32 velocity;
    self->unk6++;
    self->air_state = 0;
    if ((self->unk2 & 0xF) == 2) {
        self->x_speed = 0;
    } else {
        velocity = self->unk15 != 0 ? FIXED(4) : -FIXED(4);
        self->x_speed = velocity;
    }
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    func_800179A4(self, 0);
    SP_CUR_MAIN_OBJ->ext.main_48.unk80 = 0x3C;
}
