/* Adapted from sozud/mmx4 @6a6b455 src/main/stage_objects.c:start_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature 503943cdb46f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_80029478(s8 arg0, s8 arg1, s8 arg2) {
    background_objects[0].unk37 = arg0;
    background_objects[0].unk46 = arg1;
    background_objects[0].unk3E.bytes[1] = arg1;
    background_objects[0].unk3D = arg2;
    background_objects[0].unk3B = arg2;
    background_objects[0].unk34 |= 1;
}
