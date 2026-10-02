/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80018EEC, AGPL-3.0; proven shared with X6 by exact signature e997ebfce7dc (see THIRD_PARTY.md). */
#include "common.h"
extern s32 D_800E2ED0;
extern s32 D_800E2ED4;
extern volatile s32 D_800E2F2C;

void func_8001B784(void) {
    do {

    } while (D_800E2F2C != 0);
    D_800E2ED0 = D_800E2ED4;
}
