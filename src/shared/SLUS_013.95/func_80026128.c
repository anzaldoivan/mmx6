/* Adapted from sozud/mmx4 @29b62af src/main/144A4.c:func_800241E8, AGPL-3.0; proven shared with X6 by exact signature df4775baa321 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern X4_P_TAG* D_8008EB08[2][4][8];
extern X4_P_TAG* D_80090D70[2][4][8];

void func_80026128(void) {
    u32 buffer;
    u32 i;
    u32 j;

    buffer = SP_DRAW_BUFFER;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            D_80090D70[buffer][i][j] = NULL;
            D_8008EB08[buffer][i][j] = (X4_P_TAG*)&D_80090D70[buffer][i][j];
        }
    }
}
