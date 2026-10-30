/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_fade, AGPL-3.0; proven shared with X6 by exact signature 246e79a6823b (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04();
M2C_UNK clear_object_slot(void*, void*);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80049670(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    ((void (*)())func_80017A04)(arg0);
    if (arg0->animation_step.fields.relative_step < 0) {
        ((void (*)())clear_object_slot)(arg0);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
}
