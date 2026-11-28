/* Adapted from sozud/mmx4 @4e16dfc src/main/object_motion.c:func_8002B9F0, AGPL-3.0; proven shared with X6 by exact signature 5e8e8871519a (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/globals.h"

void func_8002D454(s32* arg0, s32* arg1, u8 arg2) {
    s16 var_a3, var_v0;
    s16 var_v1;

    if (arg2 < 0x10) {
        var_a3 = 1;
        if (arg2 < 8) {
            var_v1 = 8 - arg2;
            var_v0 = 1;
        } else {
            var_v1 = arg2 - 8;
            var_v0 = -1;
        }
    } else {
        var_a3 = -1;
        if (arg2 < 0x18) {
            var_v1 = 0x18 - arg2;
            var_v0 = -1;
        } else {
            var_v1 = arg2 - 0x18;
            var_v0 = 1;
        }
    }
    *arg0 = g_angle_x_speeds[var_v1] * var_v0;
    *arg1 = g_angle_y_speeds[var_v1] * var_a3;
}

#include "common.h"
#include "mmx6/globals.h"

s32 func_8002D4F4(void) {
    s32 var_v0;

    var_v0 = (D_80097120 & 0xF) != 0;
    if (D_80097120 & 0x1B0) {
        var_v0 += 1;
    }
    return var_v0;
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/object_motion.c:get_layout_screen, AGPL-3.0; proven shared with X6 by exact signature b57657e8090d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
extern struct X4_BackgroundObj background_objects[3];

s16 func_8002D51C(s16 arg0, s16 arg1, s16 arg2) {
    struct X4_BackgroundObj* temp_v1 = &background_objects[arg0];
    s16 var_x, var_y;
    s16 temp;

    var_x = (temp_v1->x_pos.i.hi + arg1) / 256;
    var_y = (temp_v1->y_pos.i.hi + arg2) / 256;
    temp = var_x + (arg0 * g_tilemap_layer_stride + g_tilemap_width * var_y);

    return SP_BG_TILEMAP[temp];
}
