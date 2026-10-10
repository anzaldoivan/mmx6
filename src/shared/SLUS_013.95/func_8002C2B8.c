/* Adapted from sozud/mmx4 @29b62af src/main/objects.c:func_8002AB20, AGPL-3.0; proven shared with X6 by exact signature 7632243f87cd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj D_800971F8[3];

void func_8002C2B8() {
    s8 fill = 0;
    u32 i;
    for (i = 0; i < 3; i++) {
        s8* a0 = (u8*)&D_800971F8[i];
        s32 v1 = sizeof(struct X4_BackgroundObj) - 1;
        do {
            *a0++ = fill;
        } while (v1-- != 0);
        D_800971F8[i].unk2 = i;
    }
}
