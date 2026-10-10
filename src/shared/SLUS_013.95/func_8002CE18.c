/* Adapted from sozud/mmx4 @29b62af src/main/objects.c:func_8002B468, AGPL-3.0; proven shared with X6 by exact signature 824e92a3c988 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj D_8009B7B0[0x20];

struct X4_EffectObj* func_8002CE18(s8 id, s8 arg1) {
    struct X4_EffectObj* effect;
    s8 i;

    i = 0;
    if (id >= 0) {
        do {
            effect = &D_8009B7B0[i];
            if (effect->active != 0 && effect->id == id &&
                effect->unk2 == arg1) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    } else {
        id &= 0x7F;
        do {
            effect = &D_8009B7B0[i];
            if (effect->active != 0 && effect->id == id) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    }
}
