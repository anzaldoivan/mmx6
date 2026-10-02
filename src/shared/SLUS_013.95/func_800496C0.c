/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_attach, AGPL-3.0; proven shared with X6 by exact signature 3cea93403e4f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_VisualAttachmentOffset D_80077BF4[2];

void func_800496C0(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    arg0->unk15 = arg1->unk15;
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi + D_80077BF4[arg1->unk2].x;
    } else {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - D_80077BF4[arg1->unk2].x;
    }
    arg0->y_pos.i.hi = arg1->y_pos.i.hi + D_80077BF4[arg1->unk2].y;
}
