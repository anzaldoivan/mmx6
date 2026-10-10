/* Adapted from sozud/mmx4 @29b62af src/main/memcard.c:func_8001CE84, AGPL-3.0; proven shared with X6 by exact signature e642975dc52e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern long func_80069F34(char*);
extern const struct X4_MemcardPath D_800100AC;

s32 func_8001C6C0(s32 device_num) {

    struct X4_MemcardPath buf = D_800100AC;

    buf.path[2] += device_num;
    return func_80069F34(buf.path) ^ 1;
}
