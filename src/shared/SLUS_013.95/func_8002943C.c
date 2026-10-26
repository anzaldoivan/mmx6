/* Adapted from sozud/mmx4 @807a01b src/main/stage_objects.c:start_screen_shake_x, AGPL-3.0; proven shared with X6 by exact signature 43e71a929bf8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];

void func_8002943C(s8 arg0, s8 arg1, s8 arg2) {
    background_objects[0].unk36 = arg0;
    background_objects[0].unk45 = arg1;
    background_objects[0].unk3E.bytes[0] = arg1;
    background_objects[0].unk3C = arg2;
    background_objects[0].unk3A = arg2;
    background_objects[0].unk34 |= 0x10;
}
