/* Adapted from sozud/mmx4 @807a01b src/main/misc/misc_25_sentry_flash.c:sentry_flash_animate, AGPL-3.0; proven shared with X6 by exact signature 7ce572c2f092 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(struct X4_BaseObj*, s32, s32))func_8002CCB0)
s32 func_8002CAB4(struct X4_BaseObj*);

M2C_UNK func_80017A04();
void func_800EDCE0(struct X4_MiscObj* self) {
    func_80017A04(ANIMATED_OBJECT(self));
    if (func_8002CAB4(BASE_OBJECT(self)) == 0) {
        func_8002CCB0(BASE_OBJECT(self), 0x30, 0x10);
        if (self->animation_step.fields.relative_step != 0) {
            return;
        }
    }
    self->state++;
}
#undef func_8002CCB0
