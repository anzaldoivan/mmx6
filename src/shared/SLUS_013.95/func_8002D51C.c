/* Adapted from sozud/mmx4 @29b62af src/main/object_motion.c:get_layout_screen, AGPL-3.0; proven shared with X6 by exact signature b57657e8090d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800CD338;
extern u16 D_8008EC10;

s16 func_8002D51C(s16 arg0, s16 arg1, s16 arg2) {
    struct X4_BackgroundObj* temp_v1 = &D_800971F8[arg0];
    s16 var_x, var_y;
    s16 temp;

    var_x = (temp_v1->x_pos.i.hi + arg1) / 256;
    var_y = (temp_v1->y_pos.i.hi + arg2) / 256;
    temp = var_x + (arg0 * D_8008EC10 + D_800CD338 * var_y);

    return SP_BG_TILEMAP[temp];
}
