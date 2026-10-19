#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
struct X4_EffectObj* func_8002C3F8(void);

void func_8001E730(void) {
    struct X4_EffectObj* effect;

    if (D_800CCED0.unk1E == 0) {
        effect = func_8002C3F8();
        if (effect != 0) {
            effect->active = 1;
            effect->id = 0x1B;
            return;
        }
        D_800CCED0.unk1E = 1;
    }
}
