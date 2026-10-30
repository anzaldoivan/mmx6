/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_init, AGPL-3.0; proven shared with X6 by exact signature 339a3fd19fc8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 set_animation(void*, s32);

void func_800E9B0C(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk54 = 3;
    arg0->unk16 = VISUAL_SATURN_LAYER(2);
    set_animation(arg0, 0x19);
}
