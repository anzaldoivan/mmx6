/* Adapted from sozud/mmx4 @807a01b src/main/memcard.c:func_8001CEDC, AGPL-3.0; proven shared with X6 by exact signature a1a1bb6682a3 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
M2C_UNK TestEvent(s32);
extern s32 D_800E2F70;
extern s32 D_800E2F74;
extern s32 D_800E2F78;
extern s32 D_800E2F7C;

s32 func_8001C824(void) {
    const long MAX_LOOPS = 250000;
    long var_s0;

    for (var_s0 = MAX_LOOPS - 1; var_s0 != 0; var_s0--) {
        if (TestEvent(D_800E2F70)) {
            return 0;
        }
        if (TestEvent(D_800E2F74)) {
            return 1;
        }
        if (TestEvent(D_800E2F78)) {
            return 2;
        }
        if (TestEvent(D_800E2F7C)) {
            return 3;
        }
    }
    return 3;
}
