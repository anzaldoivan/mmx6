#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj* D_800E4498[22];

void func_8005378C(struct X4_EffectObj* self) {
    D_800E4498[self->ext.effect_24.unk1B]->unk5++;
    if (++self->ext.effect_24.unk1B == 0x16) {
        self->ext.effect_24.timer = 0x3C;
        self->unk5++;
    }
}
