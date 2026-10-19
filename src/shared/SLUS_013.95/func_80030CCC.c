#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800E41A6;
extern s16 D_800E41B0[][4];

u8 func_80030234(struct X4_PlayerObj* obj, s16 px, s16 py);

s32 func_80030CCC(struct X4_PlayerObj* self, s16 x, s16 y) {
    s32 i;

    for (i = 0; i < D_800E41A6; i++) {
        if (x >= D_800E41B0[i][0] && D_800E41B0[i][1] >= x &&
            y >= D_800E41B0[i][2] && D_800E41B0[i][3] >= y) {
            return 0x38;
        }
    }
    return func_80030234(self, x, y);
}
