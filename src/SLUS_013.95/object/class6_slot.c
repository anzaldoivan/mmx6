// prog SLUS_013.95 | system object | range 0x8002C7F0-0x8002C84C
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

// 0x8002C7F0 alloc_class6_slot: returns a cleared free slot of the class 6 pool g_class6_slots.
// basis: code code:src/SLUS_013.95/object/class6_slot.c:17 via=g_class6_slots
// evidence: origin table type 0x6 (docs/leads/objects.tsv:344), scan of g_class6_slots for active == 0
// callers: open_text_box
// unnamed callers: func_80042EB4, func_8004D318, func_800538BC and others
struct X4_QuadObj* alloc_class6_slot(void) {
    struct X4_QuadObj* p;
    u8* b;
    s32 i;

    for (p = (struct X4_QuadObj*)g_class6_slots;
         p < (struct X4_QuadObj*)(g_class6_slots + 0x1800); p++) {
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
