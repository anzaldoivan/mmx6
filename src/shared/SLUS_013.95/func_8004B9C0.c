#include "common.h"
#include "mmx6/x4.h"
extern s16 D_80077E98[][16];
extern struct X4_QuadMotionData D_80078138[22];
extern u8 D_800E4478[0x10];

void func_8004B9C0(struct X4_QuadObj* arg0) {
    s32 idx;

    arg0->bg_offset = -1;
    idx = arg0->unk2;
    arg0->unk34 = 4;
    arg0->unk36 = 0x10;
    arg0->on_screen = 1;
    arg0->x_pos.val = 0;
    arg0->y_pos.val = 0;
    arg0->ext.quad_2.x_scale.bytes.fraction = 0;
    arg0->state++;
    if (idx < 0x15) {
        arg0->active |= 0x10;
        arg0->vertices[0].x.i.hi = D_80077E98[idx][0];
        arg0->vertices[0].y.i.hi = D_80077E98[idx][1];
        arg0->vertices[1].x.i.hi = D_80077E98[idx][2];
        arg0->vertices[1].y.i.hi = D_80077E98[idx][3];
        arg0->vertices[2].x.i.hi = D_80077E98[idx][4];
        arg0->vertices[2].y.i.hi = D_80077E98[idx][5];
        arg0->vertices[3].x.i.hi = D_80077E98[idx][6];
        arg0->vertices[3].y.i.hi = D_80077E98[idx][7];
    } else {
        arg0->vertices[0].x.val = D_80078138[idx].vertex[0] << 16;
        arg0->vertices[1].x.val = D_80078138[idx].vertex[2] << 16;
        arg0->vertices[2].x.val = D_80078138[idx].vertex[2] << 16;
        arg0->vertices[3].x.val = D_80078138[idx].vertex[0] << 16;
        arg0->vertices[0].y.val = D_80078138[idx].vertex[1] << 16;
        arg0->vertices[1].y.val = D_80078138[idx].vertex[3] << 16;
        arg0->vertices[2].y.val = D_80078138[idx].vertex[3] << 16;
        arg0->vertices[3].y.val = D_80078138[idx].vertex[1] << 16;
    }
    if (arg0->unk2 == 0x15) {
        arg0->ext.quad_2.x_scale.bytes.integer = 0xF;
    } else {
        arg0->ext.quad_2.x_scale.bytes.integer = 0xA;
    }
    arg0->ext.quad_2.y_scale.bytes.fraction = 0;
    if (arg0->unk2 == 0) {
        D_800E4478[0] = 0;
    }
}
