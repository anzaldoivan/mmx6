/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002CC98, AGPL-3.0; proven shared with X6 by exact signature 8fa4d2d2edd1 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_800307CC(struct X4_PlayerObj* arg0, u8 arg1);

void func_800306F4(struct X4_PlayerObj* arg0) {
    s16 temp_v0;

    temp_v0 = D_800E41A0 - D_800E4194;
    if ((func_800307CC(arg0, func_80030304(arg0, D_800E419E, temp_v0)) == 0) &&
        (func_800307CC(arg0, func_80030304(arg0, D_800E419E - D_800E4192,
                                           temp_v0)) == 0)) {
        func_800307CC(
            arg0, func_80030304(arg0, D_800E419E + D_800E4192 - 1, temp_v0));
    }
}
