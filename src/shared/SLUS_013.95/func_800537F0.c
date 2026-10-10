/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_finish, AGPL-3.0; proven shared with X6 by exact signature 7ccb25922a7c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800537F0(struct X4_EffectObj* self) {
    self->ext.effect_24.unk1A = 0xA;
    if (--self->ext.effect_24.timer == 0) {
        self->state++;
    }
}
