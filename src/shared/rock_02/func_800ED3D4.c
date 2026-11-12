/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_10_dragonfly.c:dragonfly_carry, AGPL-3.0; proven shared with X6 by exact signature d78453aaa177 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800FAE78[])(struct X4_MainObj*);

void func_800ED3D4(struct X4_MainObj* self) {
    D_800FAE78[self->action_phase](self);
    animate_object((struct X4_PlayerObj*)self);
}
