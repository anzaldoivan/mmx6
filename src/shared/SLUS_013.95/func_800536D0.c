/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_wait, AGPL-3.0; proven shared with X6 by exact signature ec91c859e783 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800536D0(struct X4_EffectObj* self) {
    if (--self->ext.effect_24.timer == 0) {
        self->unk5++;
    }
}
