#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
struct X4_EffectObj* alloc_class3_slot(void);

void func_8001E730(void) {
    struct X4_EffectObj* effect;

    if (g_playthrough_state.unk1E == 0) {
        effect = alloc_class3_slot();
        if (effect != 0) {
            effect->active = 1;
            effect->id = 0x1B;
            return;
        }
        g_playthrough_state.unk1E = 1;
    }
}
