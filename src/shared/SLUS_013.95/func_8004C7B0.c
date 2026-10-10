/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_08_flash_band.c:flash_band_widen, AGPL-3.0; proven shared with X6 by exact signature f8c67d3d4451 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
void func_800328B0(); /* was M2C_UNK (W15 regate of 328B0) */
void func_8004C7B0(struct X4_QuadObj* arg0) {
    arg0->vertices[0].x.val += arg0->ext.ready_line.x_vel.val;
    arg0->vertices[3].x.val -= arg0->ext.ready_line.x_vel.val;
    arg0->ext.ready_line.x_vel.val += FIXED(4);
    func_800328B0(arg0);
    if (arg0->vertices[0].x.i.hi > 0x14A) {
        arg0->state++;
    }
}
