#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_EffectObj* func_8002C3F8(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_EngineObj D_800CCED0;

void func_800F94C4(struct X4_MainObj* self) {
    u8* p;

    if ((D_800CCED0.unkF == 0) && (D_800970A5 == 0x14)) {
        if (D_800CCED0.stage != 0xC) {
            func_8003D308(0x1D, 0x40);
        }
        p = func_8002C3F8();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(void**)&self->ext = p;
        }
        self->unk7C = 0x1E;
        self->unk6++;
    }
}
