/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_22_missile_smoke.c:missile_smoke_init, AGPL-3.0; proven shared with X6 by exact signature 350f949ca2ac (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8004B50C(struct X4_VisualObj*);
s32 func_800179A4(void*, s32);

void func_8004B4BC(struct X4_VisualObj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    if (arg0->unk2 != 0x10) {
        arg0->unk15 = 0;
        func_8004B50C(arg0);
    } else {
        arg0->unk16 = 2;
        func_800179A4(arg0, 0x25);
    }
}
