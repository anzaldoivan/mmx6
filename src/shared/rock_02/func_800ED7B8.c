// rolefeed (3.1 T4): func_800ED7B8 of src/rock_02/E9860.c
#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_48_sentry_drone.c:sentry_drone_spread_repeat, AGPL-3.0; proven shared with X6 by exact signature be9839e079dd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800EC9C8(struct X4_MainObj*);

void func_800ED7B8(struct X4_MainObj* self) {
    if (SP_CUR_MAIN_OBJ->ext.main_48.unk82 < 9) {
        func_800EC9C8(self);
        self->action_phase -= 2;
    } else {
        self->action_phase++;
    }
}
