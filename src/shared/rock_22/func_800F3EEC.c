/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_19_surface_hopper.c:surface_hopper_leap_start, AGPL-3.0; proven shared with X6 by exact signature f3e8264e3395 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800FC6D4[];
s32 set_animation(void*, s32);

void func_800F3EEC(struct X4_MainObj* self) {
    self->unk6 = 1;
    self->unk7C = 0;
    set_animation(
        self, D_800FC6D4[SP_CUR_MAIN_OBJ->ext.main_19.animation_index >> 1]);
}
