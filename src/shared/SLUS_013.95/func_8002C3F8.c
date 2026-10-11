#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EffectObj D_8009B7B0[0x20];

struct X4_EffectObj* func_8002C3F8(void) {
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
