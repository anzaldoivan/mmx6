#include "common.h"
#include "mmx6/x4.h"

extern struct X4_LayerObj D_800C4778[4];

// 0x8002C950 alloc_class7_slot: returns a cleared free slot of the class 7 pool D_800C4778.
// basis: code origin table type 0x7 (docs/leads/objects.tsv:345), scan of D_800C4778 for active == 0
// callers: none known
struct X4_LayerObj* alloc_class7_slot(void) {
    struct X4_LayerObj* p;
    u8* b;
    s32 i;

    for (p = D_800C4778; p < &D_800C4778[4]; p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(struct X4_LayerObj) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
