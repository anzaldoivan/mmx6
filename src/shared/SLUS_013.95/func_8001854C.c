#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80018060(M2C_UNK, M2C_UNK);
extern u8 D_8007093C[];
extern struct X4_EngineObj D_800CCED0;

void func_8001854C(void) {
    struct X4_EngineObj* e = &D_800CCED0;

    if (*(u16*)&e->stage != 0x10F) {
        ((void (*)(M2C_UNK, M2C_UNK, void*))func_80018060)(
            D_8007093C[(e->stage * 8 + e->substage * 4) +
                       *(s8*)&e->controlled_player * 2],
            0x63, e);
    }
}
