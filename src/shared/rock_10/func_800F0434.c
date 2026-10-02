/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_27_dash_gunner.c:dash_gunner_explode, AGPL-3.0; proven shared with X6 by exact signature 7e98e0cffd71 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

void func_800F0434(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        self->state = 3;
    } else if (--self->unk7E == 0) {
        self->unk7E = 6;
        func_80049EBC(self, 1, 16, 16);
    }
}
