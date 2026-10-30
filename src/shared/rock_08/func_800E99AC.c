/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_init, AGPL-3.0; proven shared with X6 by exact signature 561f8a99cfb3 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 set_animation(void*, s32);

void func_800E99AC(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk54 = 0xFF;
    arg0->unk56 = 0xFF;
    arg0->unk16 = VISUAL_SATURN_LAYER(6);
    set_animation(arg0, 0x15);
}
