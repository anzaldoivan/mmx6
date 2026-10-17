#include "common.h"
#include "mmx6/x4.h"

u8 func_80030234(struct X4_PlayerObj*, s16, s16);

s32 func_800ED014(struct X4_PlayerObj* arg0) {
    s32 t;

    t = ((s32(*)())func_80030234)(arg0, arg0->x_pos.i.hi, arg0->y_pos.i.hi) &
        0xFF;
    if (t == 0) {
        // !FAKE: goto: shared return blocks; nested ifs compile to store-flags
        goto zero;
    }
    if (t < 0) {
        // !FAKE: goto: shared return blocks; nested ifs compile to store-flags
        goto one;
    }
    if (t >= 0x30) {
        // !FAKE: goto: shared return blocks; nested ifs compile to store-flags
        goto one;
    }
    if (t < 0x25) {
        // !FAKE: goto: shared return blocks; nested ifs compile to store-flags
        goto one;
    }
zero:
    return 0;
one:
    return 1;
}
