#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EffectObj D_8009B7B0[0x20];

// 0x8002C3F8 alloc_class3_slot: returns a cleared free slot of the class 3 pool D_8009B7B0.
// basis: code origin table type 0x3 (docs/leads/objects.tsv:341), scan of D_8009B7B0 for active == 0
// callers: func_8001E730, func_80053578 and overlay objects (rock_02 func_800F009C and others)
struct X4_EffectObj* alloc_class3_slot(void) {
    struct X4_EffectObj* effect;
    struct X4_EffectObj* end;
    s8* q;
    s32 k;

    effect = D_8009B7B0;
    end = &D_8009B7B0[0x60];
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
