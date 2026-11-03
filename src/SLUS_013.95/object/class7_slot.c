// prog SLUS_013.95 | system object | range 0x8002C950-0x8002C9AC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

// 0x8002C950 alloc_class7_slot: returns a cleared free slot of the class 7 pool g_class7_slots.
// basis: code code:src/SLUS_013.95/object/class7_slot.c:15 via=g_class7_slots
// evidence: origin table type 0x7 (docs/leads/objects.tsv:345), scan of g_class7_slots for active == 0
// callers: none known
struct X4_LayerObj* alloc_class7_slot(void) {
    struct X4_LayerObj* p;
    u8* b;
    s32 i;

    for (p = g_class7_slots; p < &g_class7_slots[4]; p++) {
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
