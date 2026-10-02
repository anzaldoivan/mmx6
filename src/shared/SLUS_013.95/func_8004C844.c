/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_07_ready_line.c:ready_line_sweep, AGPL-3.0; proven shared with X6 by exact signature 5aa466ee5359 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void* func_8002C530();
extern u16 D_800782B0[8];

void func_8004C844(struct X4_QuadObj* arg0) {
    u16* verts;
    struct X4_EffectObj* temp_s1;
    struct X4_MiscObj* misc_obj;
    switch (arg0->unk5) {
    case 0:
        arg0->unk5 = 1;
        // set position of blue line that goes left to right before
        // ready text appears
        arg0->x_pos.i.hi = -320;
        arg0->y_pos.i.hi = 112;
        verts = D_800782B0;
        arg0->vertices[0].x.i.hi = *verts++;
        arg0->vertices[0].y.i.hi = *verts++;
        arg0->vertices[1].x.i.hi = *verts++;
        arg0->vertices[1].y.i.hi = *verts++;
        arg0->vertices[2].x.i.hi = *verts++;
        arg0->vertices[2].y.i.hi = *verts++;
        arg0->vertices[3].x.i.hi = *verts++;
        arg0->vertices[3].y.i.hi = *verts;
        arg0->ext.ready_line.x_vel.val = FIXED(32);
        arg0->ext.ready_line.y_vel.val = 0;
        arg0->ext.ready_line.x_accel.val = 0;
        arg0->ext.ready_line.y_accel.val = 0;
        func_8004D074(arg0);
        return;
    case 1:
        temp_s1 = arg0->link.owner;
        // spawn "READY" text and shadow when blue line reaches center of screen
        if ((arg0->x_pos.i.hi >= 0 && arg0->x_pos.i.hi <= 2) &&
            (temp_s1->ext.unk_effect.unk15 == 0)) {
            misc_obj = func_8002C530();
            if (misc_obj != NULL) {
                misc_obj->active = 1;
                misc_obj->id = 0x12;
                misc_obj->unk2 = 0;
                temp_s1->ext.unk_effect.unk15 = 0;
                misc_obj->ext.ready_text.owner = arg0->link.owner;
            }
            misc_obj = func_8002C530();
            if (misc_obj != NULL) {
                misc_obj->active = 1;
                misc_obj->id = 0x12;
                misc_obj->unk2 = 1;
                temp_s1->ext.unk_effect.unk15 = 0;
                misc_obj->ext.ready_text.owner = arg0->link.owner;
            }
        }
        if (arg0->x_pos.i.hi >= 320) {
            arg0->unk5 = 2;
            return;
        }
        func_8004D074(arg0);
        return;
    case 2:
        temp_s1 = arg0->link.owner;
        temp_s1->ext.unk_effect.unk14 = 0;
        arg0->state = 2;
        arg0->unk5 = 0;
        return;
    }
}
