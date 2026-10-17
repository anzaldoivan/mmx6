#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj D_8009B7B0[0x20];

void func_8002C0DC(s32 arg0, s32 arg1_) {
    s8 id = arg0;
    s8 arg1 = arg1_;
    struct X4_EffectObj* effect;
    s8 i;

    if (id >= 0) {
        for (i = 0; i < 0x20; i++) {
            effect = &D_8009B7B0[i];
            if (effect->active != 0 && effect->id == id &&
                effect->unk2 == arg1) {
                effect->active = 0;
                effect->id = 0;
                effect->unk2 = 0;
                effect->on_screen = 0;
                effect->state = 0;
                effect->unk5 = 0;
                effect->unk6 = 0;
                effect->unk7 = 0;
            }
        }
    } else {
        id &= 0x7F;
        for (i = 0; i < 0x20; i++) {
            effect = &D_8009B7B0[i];
            if (effect->active != 0 && effect->id == id) {
                effect->active = 0;
                effect->id = 0;
                effect->unk2 = 0;
                effect->on_screen = 0;
                effect->state = 0;
                effect->unk5 = 0;
                effect->unk6 = 0;
                effect->unk7 = 0;
            }
        }
    }
}
