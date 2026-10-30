#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj g_displayed_sprites[];

// 0x8002C530 alloc_sprite_slot: free slot in displayed sprites table.
// basis: community tweaks-index.tsv:379
// callers: func_8001CC1C, func_8001D51C, func_8001D7AC, func_8001DA20 and others
void* alloc_sprite_slot(void) {
    s8* p;
    s8* q;
    s32 k;

    for (p = (s8*)g_displayed_sprites; p < (s8*)g_displayed_sprites + 0x2400;
         p += 0x60) {
        if (*p == 0) {
            q = p;
            for (k = 0x5F; k != -1; k--) {
                *q++ = 0;
            }
            return p;
        }
    }
    return 0;
}
