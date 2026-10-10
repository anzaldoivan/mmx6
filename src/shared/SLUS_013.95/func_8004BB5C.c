#include "common.h"
#include "mmx6/x4.h"
extern s16 D_80077E98[][16];
extern struct X4_QuadMotionData D_80078138[22];
extern u8 D_800E4478[0x10];

void func_8004BB5C(struct X4_QuadObj* arg0) {
    u8 integer = arg0->ext.quad_2.x_scale.bytes.integer;

    if (integer == 0) {
        arg0->unk5++;
        if (arg0->unk2 == 0x15) {
            D_800E4478[0] = 1;
        } else {
            arg0->active &= ~0x10;
            arg0->vertices[0].x.i.hi = D_80077E98[arg0->unk2][8];
            arg0->vertices[0].y.i.hi = D_80077E98[arg0->unk2][9];
            arg0->vertices[1].x.i.hi = D_80077E98[arg0->unk2][10];
            arg0->vertices[1].y.i.hi = D_80077E98[arg0->unk2][11];
            arg0->vertices[2].x.i.hi = D_80077E98[arg0->unk2][12];
            arg0->vertices[2].y.i.hi = D_80077E98[arg0->unk2][13];
            arg0->vertices[3].x.i.hi = D_80077E98[arg0->unk2][14];
            arg0->vertices[3].y.i.hi = D_80077E98[arg0->unk2][15];
        }
    } else {
        arg0->ext.quad_2.x_scale.bytes.integer = integer - 1;
        if (arg0->unk2 == 0x15) {
            arg0->vertices[0].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
            arg0->vertices[1].x.val += FIXED(D_80078138[arg0->unk2].speed[0]);
            arg0->vertices[2].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
            arg0->vertices[3].x.val += FIXED(D_80078138[arg0->unk2].speed[2]);
        } else {
            {
                s32 start = D_80077E98[arg0->unk2][0];
                s32 end = D_80077E98[arg0->unk2][8];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[0].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][1];
                s32 end = D_80077E98[arg0->unk2][9];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[0].y.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][2];
                s32 end = D_80077E98[arg0->unk2][10];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[1].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][3];
                s32 end = D_80077E98[arg0->unk2][11];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[1].y.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][4];
                s32 end = D_80077E98[arg0->unk2][12];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[2].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][5];
                s32 end = D_80077E98[arg0->unk2][13];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[2].y.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][6];
                s32 end = D_80077E98[arg0->unk2][14];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[3].x.i.hi = (end - start) * t / d + start;
            }
            {
                s32 start = D_80077E98[arg0->unk2][7];
                s32 end = D_80077E98[arg0->unk2][15];
                s32 t = 10 - arg0->ext.quad_2.x_scale.bytes.integer;
                s32 d = 10;
                arg0->vertices[3].y.i.hi = (end - start) * t / d + start;
            }
        }
    }
}
