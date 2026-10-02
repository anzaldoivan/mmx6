/* Adapted from sozud/mmx4 @29b62af src/main/2824.c:func_80012910, AGPL-3.0; proven shared with X6 by exact signature 56ff4cada450 (see THIRD_PARTY.md). */
#include "common.h"

void func_800134A4(s32 arg0) {

    u16* temp_a0 = (arg0 << 7) + 0x801F8100;

    *temp_a0 &= ~0x40;
}
