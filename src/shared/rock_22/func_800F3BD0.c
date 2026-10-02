/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_appear, AGPL-3.0; proven shared with X6 by exact signature 279ef0018214 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_800FC6A4[4];
s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();

void func_800F3BD0(struct X4_MainObj* self) {
    if (self->unk6 == 0) {
        self->unk6 = 1;
        func_800179A4(self,
                      D_800FC6A4[SP_CUR_MAIN_OBJ->ext.main_19.animation_index]);
        return;
    }

    if (self->animation_step.fields.relative_step < 0) {
        self->unk5 = 2;
        self->unk6 = 0;
        SP_CUR_MAIN_OBJ->ext.main_19.unk80 = func_8002D2D4() & 1;
    }

    func_80017A04(ANIMATED_OBJECT(self));
}
