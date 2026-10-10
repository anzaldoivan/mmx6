/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002D5E4, AGPL-3.0; proven shared with X6 by exact signature ca45eff14472 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4194;
extern s16 D_800E41A0;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
s32 func_80030C58(struct X4_PlayerObj* arg0, u8 arg1);

s32 func_80030B80(struct X4_PlayerObj* arg0, s16 arg1) {
    if (func_80030C58(
            arg0, func_80030234(arg0, arg1, D_800E41A0 - D_800E4194)) == 0) {
        if (func_80030C58(arg0, func_80030234(arg0, arg1, D_800E41A0)) == 0) {
            if (func_80030C58(
                    arg0, func_80030234(arg0, arg1,
                                        D_800E41A0 + D_800E4194 - 1)) == 0) {
                return 0;
            }
        }
    }
    return -1;
}
