/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_48_sentry_drone.c:sentry_drone_burst_repeat, AGPL-3.0; proven shared with X6 by exact signature b51be65f31c0 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800ED498(struct X4_MainObj* self) {
    struct X4_MainObj* work = SP_CUR_MAIN_OBJ;
    if (3 <= work->ext.main_48.unk82) {
        self->unk6++;
        SP_CUR_MAIN_OBJ->ext.main_48.unk82 = 0;
        SP_CUR_MAIN_OBJ->ext.main_48.unk80 = 0x14;
    } else {
        if (--work->ext.main_48.unk80 == 0) {
            self->unk6--;
        }
    }
}
