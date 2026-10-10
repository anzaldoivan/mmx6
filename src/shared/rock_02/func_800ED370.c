/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_48_sentry_drone.c:sentry_drone_dash_move, AGPL-3.0; proven shared with X6 by exact signature 0de043eb0114 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);

void func_800ED370(struct X4_MainObj* self) {
    s8 timer;
    func_80017A04(ANIMATED_OBJECT(self));
    func_8002D2B0(MOVING_OBJECT(self));
    timer = --SP_CUR_MAIN_OBJ->ext.main_48.unk80;
    if (timer == 0) {
        self->air_state = -1;
        self->unk5 = 6;
        self->unk6 = 0;
    }
}
