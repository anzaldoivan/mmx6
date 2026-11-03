// prog SLUS_013.95 | system object | range 0x8002C4C4-0x8002C52C
#include "common.h"
#include "mmx6/class4.h"

#include "mmx6/globals.h"

// 0x8002C4C4 alloc_class4_slot: returns a cleared free slot of the class 4 pool g_class4_slots.
// basis: code code:src/SLUS_013.95/object/class4_slot.c:18 via=g_class4_slots
// evidence: origin table type 0x4 (docs/leads/objects.tsv:342), scan of g_class4_slots for active == 0
// callers: init_capsule
// unnamed callers: overlay objects (rock_03 func_800EC25C and others)
void* alloc_class4_slot(void) {
    s8* p;
    s8* end;
    s8* q;
    s32 k;

    p = (s8*)g_class4_slots;
    end = p + 0x3340;
    if (p < end) {
        do {
            if (*p == 0) {
                q = p;
                k = 0xA3;
                do {
                    *q = 0;
                    k--;
                    q++;
                } while (k != -1);
                ((struct Class4Obj*)p)->attack_box = 0;
                ((struct Class4Obj*)p)->hurt_box = 0;
                ((struct Class4Obj*)p)->terrain_box = 0;
                return p;
            }
            p += 0xA4;
        } while (p < end);
    }
    return 0;
}
