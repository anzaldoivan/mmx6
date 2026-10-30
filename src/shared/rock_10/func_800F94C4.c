#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_EffectObj* alloc_class3_slot(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_EngineObj g_playthrough_state;

void func_800F94C4(struct X4_MainObj* self) {
    u8* p;

    if ((g_playthrough_state.unkF == 0) && (D_800970A5 == 0x14)) {
        if (g_playthrough_state.stage != 0xC) {
            func_8003D308(0x1D, 0x40);
        }
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(void**)&self->ext = p;
        }
        self->unk7C = 0x1E;
        self->unk6++;
    }
}
