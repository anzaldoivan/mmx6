/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_init, AGPL-3.0; proven shared with X6 by exact signature 339a3fd19fc8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_800179A4(void*, s32);

void func_800E9B0C(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk54 = 3;
    arg0->unk16 = 2;
    func_800179A4(arg0, 0x19);
}
