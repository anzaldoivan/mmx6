/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002D32C, AGPL-3.0; proven shared with X6 by exact signature 42673ebd7e4e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E419E;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);

s32 func_800309F8(struct X4_PlayerObj* arg0, s16 arg1, s32 arg2) {
    if (func_80030AE8(arg0, func_80030234(arg0, D_800E419E, arg1), arg2) == 0) {
        if (func_80030AE8(arg0,
                          func_80030234(arg0, D_800E419E - D_800E4192, arg1),
                          arg2) == 0) {
            if (func_80030AE8(
                    arg0,
                    func_80030234(arg0, D_800E419E + D_800E4192 - 1, arg1),
                    arg2) == 0) {
                return 0;
            }
        }
    }
    return -1;
}
