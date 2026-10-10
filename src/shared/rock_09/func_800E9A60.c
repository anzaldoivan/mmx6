/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_07_water_wake.c:water_wake_main, AGPL-3.0; proven shared with X6 by exact signature b82c7ed308c9 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800F5500[])(struct X4_VisualObj*, struct X4_PlayerObj*);
M2C_UNK func_8002C9B0();
M2C_UNK func_8002CB50();
u8 func_8002FF70(struct X4_PlayerObj*);

void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    if (arg1->hp == 0 || arg1->state == 3) {
        func_8002C9B0(arg0);
        return;
    }
    arg0->unk15 = arg1->unk15;
    if (arg0->unk2 & 1) {
        arg0->x_pos.val = arg1->x_pos.val + FIXED(8);
    } else {
        arg0->x_pos.val = arg1->x_pos.val + FIXED(-8);
    }
    arg0->y_pos.val = arg1->y_pos.val;
    D_800F5500[arg0->unk5](arg0, arg1);
    if (arg1->active == 0) {
        arg0->on_screen = 0;
    }
    if (func_8002FF70(arg1) != 0x24) {
        arg0->on_screen = 0;
    }
    if (arg0->on_screen != 0) {
        func_8002CB50(arg0);
    }
}
