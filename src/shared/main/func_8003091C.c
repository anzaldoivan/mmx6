/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002D25C, AGPL-3.0; proven shared with X6 by exact signature 0de06b22f1f5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800E4191;
extern s16 D_800E4194;
extern s16 D_800E4198;
extern s16 D_800E419C;
extern s16 D_800E41A4;
s32 func_800309F8(struct X4_PlayerObj*, s16, s32);

s32 func_8003091C(struct X4_PlayerObj* arg0) {
    s16 arg1;
    s32 arg2;

    if (D_800E4191 & 4) {
        arg2 = 0;
        arg1 = D_800E419C + D_800E41A4 + D_800E4198 - D_800E4194;
    } else {
        arg2 = 1;
        arg1 = D_800E419C + D_800E41A4 + D_800E4198 + D_800E4194 - 1;
    }

    if (func_800309F8(arg0, arg1, arg2) == 0) {
        arg0->y_pos.i.lo = 0;
        arg0->y_pos.i.hi += D_800E41A4;
        return 0;
    } else {
        return -1;
    }
}
