/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_wait_tiles, AGPL-3.0; proven shared with X6 by exact signature f64138f8e32d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj* D_800E4498[22];

void func_80053704(struct X4_EffectObj* self) {
    struct X4_EffectObj* spawned;
    struct X4_EffectObj** entry;
    u32 index;
    s32 count;
    s32 expected;

    spawned = self->ext.effect_24.spawned_effect;
    if (spawned->id != 4 || *(u16*)spawned == 0x400) {
        index = 0;
        count = 0;
        expected = 1;
        entry = D_800E4498;
        do {
            if ((*entry)->unk5 == expected) {
                count++;
            }
            index++;
            entry++;
        } while (index < 0x16U);
        if (count == 0x16) {
            self->ext.effect_24.unk1B = 0;
            self->unk5++;
        }
    }
}
