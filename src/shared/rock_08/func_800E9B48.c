/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_main, AGPL-3.0; proven shared with X6 by exact signature d83d6ae99f8d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8002CCB0(struct X4_BaseObj*, s32, s32);

#define M2C_UNK s32
M2C_UNK func_80017A04();
void func_800E9B48(struct X4_VisualObj* arg0) {
    struct X4_BaseObj* temp_s1 = arg0->unk50;

    arg0->x_pos.i.hi = temp_s1->x_pos.i.hi;
    arg0->y_pos.i.hi = temp_s1->y_pos.i.hi;
    if (arg0->animation_step.fields.relative_step < 0) {
        arg0->unk54--;
    }
    ((void (*)())func_80017A04)(arg0);
    if (temp_s1->state == 2) {
        arg0->state = 2;
    } else {
        if (arg0->unk54 == 0) {
            arg0->state = 2;
        }
        func_8002CCB0(arg0, 0x10, 0x10);
    }
}
