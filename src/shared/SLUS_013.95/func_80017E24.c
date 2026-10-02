/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800160AC, AGPL-3.0; proven shared with X6 by exact signature 8cc804b315e5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u16* D_800A21B0;

void func_80017E24(void) {
    u16* src = D_800A21B0;
    u16* dst = SP_BG_TILE_PIXELS;
    s32 count = (u32)((u8*)SP_BG_TILE_ATTRS - (u8*)dst) >> 1;

    while (count > 0) {
        *dst++ = *src++;
        count--;
    }
}
