// prog SLUS_013.95 | system object | range 0x8002C3F8-0x8002C454
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

// 0x8002C3F8 alloc_class3_slot: returns a cleared free slot of the class 3 pool g_class3_slots.
// basis: code code:src/SLUS_013.95/object/class3_slot.c:18 via=g_class3_slots
// evidence: origin table type 0x3 (docs/leads/objects.tsv:341), scan of g_class3_slots for active == 0
// callers: none known
// unnamed callers: func_8001E730, func_80053578 and overlay objects (rock_02 func_800F009C and others)
struct X4_EffectObj* alloc_class3_slot(void) {
    struct X4_EffectObj* effect;
    struct X4_EffectObj* end;
    s8* q;
    s32 k;

    effect = g_class3_slots;
    end = &g_class3_slots[0x60];
    if (effect < end) {
        do {
            if (effect->active == 0) {
                q = (s8*)effect;
                k = 0x2F;
                do {
                    *q = 0;
                    k--;
                    q++;
                } while (k != -1);
                return effect;
            }
        } while (++effect < end);
    }
    return 0;
}
