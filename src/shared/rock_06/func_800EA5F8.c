/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_12_ride_dust.c:ride_dust_init, AGPL-3.0; proven shared with X6 by exact signature 6eac507027d5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800F3680[];
extern u8 D_800F368C[];
s32 func_800179A4(void*, s32);

void func_800EA5F8(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    arg0->unk16 = D_800F368C[arg0->unk2];
    func_800179A4(arg0, D_800F3680[arg0->unk2]);
}
