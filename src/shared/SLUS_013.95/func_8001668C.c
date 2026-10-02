/* Adapted from sozud/mmx4 @29b62af src/main/3D88.c:func_80014140, AGPL-3.0; proven shared with X6 by exact signature 6ba38c1ddd23 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u8* D_800E0368;
extern u8 D_8009509C;
extern u8* D_800E01AC;
extern u8 D_800E01CD;
s8 func_80014D50();

void func_8001668C(void) {
    if (D_800E01CD != 0) {
        D_800E01CD = 0;
        D_800E01AC = D_800E0368;
    }
    if (func_80014D50() == -1) {
        func_800648B4(0);
        func_80064B44(CdlPause, NULL, NULL);
        D_8009509C = 0x80;
    }
}
