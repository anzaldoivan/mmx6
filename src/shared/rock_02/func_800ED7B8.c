/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_48_sentry_drone.c:sentry_drone_spread_repeat, AGPL-3.0; proven shared with X6 by exact signature be9839e079dd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800EC9C8(struct X4_MainObj*);

void func_800ED7B8(struct X4_MainObj* self) {
    if (SP_CUR_MAIN_OBJ->ext.main_48.unk82 < 9) {
        func_800EC9C8(self);
        self->unk6 -= 2;
    } else {
        self->unk6++;
    }
}
