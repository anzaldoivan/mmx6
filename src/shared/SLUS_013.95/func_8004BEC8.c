/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_03_boss_warning_quad.c:boss_warning_quad_close, AGPL-3.0; proven shared with X6 by exact signature f3f6620a97d2 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_QuadMotionData D_80078138[22];
extern u8 D_800E4478[0x10];

void func_8004BEC8(struct X4_QuadObj* arg0) {
    u8 integer = arg0->ext.quad_2.x_scale.bytes.integer;

    if (integer == 0) {
        arg0->state++;
        if (arg0->unk2 == 0x15) {
            D_800E4478[0] = 0;
        }
    } else {
        arg0->ext.quad_2.x_scale.bytes.integer = integer - 1;
        if (arg0->unk2 == 0x15) {
            arg0->vertices[0].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
            arg0->vertices[1].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
            arg0->vertices[2].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
            arg0->vertices[3].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
        } else {
            arg0->vertices[1].x.u.hi += D_80078138[arg0->unk2].speed[0] * 2;
            arg0->vertices[0].x.u.hi += D_80078138[arg0->unk2].speed[2] * 2;
            arg0->vertices[1].y.u.hi += D_80078138[arg0->unk2].speed[1] * 2;
            arg0->vertices[0].y.u.hi += D_80078138[arg0->unk2].speed[3] * 2;
        }
    }
}
