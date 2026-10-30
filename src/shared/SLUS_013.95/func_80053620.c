#include "common.h"
#include "mmx6/x4.h"

struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_EffectObj* D_800E4498[22];

void func_80053620(struct X4_EffectObj* self) {
    struct X4_QuadObj* q;

    if (self->ext.effect_24.timer == 0) {
        q = alloc_class6_slot();
        if (q != 0) {
            q->active = -0x7D;
            q->id = 3;
            q->unk2 = self->ext.effect_24.unk1B;
            D_800E4498[self->ext.effect_24.unk1B] = (struct X4_EffectObj*)q;
            self->ext.effect_24.timer = 10;
            if (++self->ext.effect_24.unk1B == 0x16) {
                self->ext.effect_24.unk1B = 0;
                self->ext.effect_24.timer = 0xB4;
                self->unk5++;
            }
        }
    } else {
        self->ext.effect_24.timer--;
    }
}
