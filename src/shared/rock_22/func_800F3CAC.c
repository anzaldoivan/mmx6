/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl_turn, AGPL-3.0; proven shared with X6 by exact signature c738d9c59df1 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();

void func_800F3CAC(struct X4_MainObj* self) {
    if (self->animation_step.fields.relative_step < 0) {
        self->unk6 = 3;
        if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index < 2) {
            func_800179A4(self, 0xB);
        } else {
            func_800179A4(self, 0xA);
        }
    }
    func_80017A04(ANIMATED_OBJECT(self));
}
