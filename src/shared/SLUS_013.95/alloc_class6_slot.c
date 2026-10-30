#include "common.h"
#include "mmx6/x4.h"

extern u8 D_8009C9B0[];

// 0x8002C7F0 alloc_class6_slot: returns a cleared free slot of the class 6 pool D_8009C9B0.
// basis: code origin table type 0x6 (docs/leads/objects.tsv:344), scan of D_8009C9B0 for active == 0
// callers: func_80042EB4, func_8004D318, func_800538BC and others
struct X4_QuadObj* alloc_class6_slot(void) {
    struct X4_QuadObj* p;
    u8* b;
    s32 i;

    for (p = (struct X4_QuadObj*)D_8009C9B0;
         p < (struct X4_QuadObj*)(D_8009C9B0 + 0x1800); p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(struct X4_QuadObj) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
