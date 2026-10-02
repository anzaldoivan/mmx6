/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_07_ready_line.c:ready_line_move, AGPL-3.0; proven shared with X6 by exact signature 067862c5794d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_8004D074(struct X4_QuadObj* arg0) {
    arg0->x_pos.val += arg0->ext.ready_line.x_vel.val;
    arg0->y_pos.val += arg0->ext.ready_line.y_vel.val;
    arg0->ext.ready_line.x_vel.val += arg0->ext.ready_line.x_accel.val;
    arg0->ext.ready_line.y_vel.val += arg0->ext.ready_line.y_accel.val;
}
