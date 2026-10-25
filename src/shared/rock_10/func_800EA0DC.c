/* Adapted from sozud/mmx4 @6a6b455 src/main/misc/misc_01_common_effect.c:common_effect_animate, AGPL-3.0; proven shared with X6 by exact signature ed471c96b830 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_80017A04();
#define func_80017A04 ((void (*)(struct X4_AnimatedObj*))func_80017A04)
void func_8002CB50(struct X4_BaseObj*);

void func_800EA0DC(struct X4_MiscObj* self) {
    func_80017A04(ANIMATED_OBJECT(self));
    if (self->animation_step.fields.event != 0) {
        self->state = 2;
    }
    func_8002CB50(BASE_OBJECT(self));
}
#undef func_80017A04
