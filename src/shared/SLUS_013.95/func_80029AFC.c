/* Adapted from sozud/mmx4 @29b62af src/main/background.c:update_screen_shake_y, AGPL-3.0; proven shared with X6 by exact signature a0d9f0b7dd5c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_80029AFC(struct X4_BackgroundObj* arg0) {
    if (--arg0->unk37 == 0) {
        arg0->unk34 &= 0xFFFE;
        return;
    }
    if (--arg0->unk3D == 0) {
        arg0->unk3E.bytes[1] ^= 0x80;
        arg0->unk3D = arg0->unk3B;
    }
    if (arg0->unk3E.bytes[1] >= 0) {
        arg0->y_pos.i.hi += arg0->unk46;
    }
}
