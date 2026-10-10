/* Adapted from sozud/mmx4 @29b62af src/main/stage_objects.c:start_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature 503943cdb46f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj D_800971F8[3];

void func_80029478(s8 arg0, s8 arg1, s8 arg2) {
    D_800971F8[0].unk37 = arg0;
    D_800971F8[0].unk46 = arg1;
    D_800971F8[0].unk3E.bytes[1] = arg1;
    D_800971F8[0].unk3D = arg2;
    D_800971F8[0].unk3B = arg2;
    D_800971F8[0].unk34 |= 1;
}
