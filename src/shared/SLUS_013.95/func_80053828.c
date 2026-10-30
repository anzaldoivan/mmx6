/* Adapted from sozud/mmx4 @807a01b src/main/effects/effect_24_boss_warning.c:boss_warning_main, AGPL-3.0; proven shared with X6 by exact signature f335fb55e436 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_8007ACE8[])(struct X4_EffectObj*);
s32 play_sound(s32, s32, void*);

void func_80053828(struct X4_EffectObj* self) {
    D_8007ACE8[self->unk5](self);
    if (self->ext.effect_24.unk1A == 0) {
        play_sound(0, SATURN_SOUND(0x13, 0x15), 0);
        self->ext.effect_24.unk1A = 0x3C;
    } else {
        self->ext.effect_24.unk1A--;
    }
}
