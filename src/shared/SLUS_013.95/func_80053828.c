/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_main, AGPL-3.0; proven shared with X6 by exact signature f335fb55e436 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_8007ACE8[])(struct X4_EffectObj*);
s32 func_80016C48(s32, X4_arg_u8, void*);

void func_80053828(struct X4_EffectObj* self) {
    D_8007ACE8[self->unk5](self);
    if (self->ext.effect_24.unk1A == 0) {
        func_80016C48(0, 0x13, 0);
        self->ext.effect_24.unk1A = 0x3C;
    } else {
        self->ext.effect_24.unk1A--;
    }
}
