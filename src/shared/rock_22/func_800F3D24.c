/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl_turn_end, AGPL-3.0; proven shared with X6 by exact signature f1c046e43f2b (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80017A04();

void func_800F3D24(struct X4_MainObj* self) {
    if (self->animation_step.fields.relative_step < 0) {
        self->unk6 = 0;
        SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
    }
    func_80017A04(ANIMATED_OBJECT(self));
}
