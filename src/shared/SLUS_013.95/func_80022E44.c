/* Adapted from sozud/mmx4 @6a6b455 src/main/14A60.c:func_80024260, AGPL-3.0; proven shared with X6 by exact signature ce7e7513ad74 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern X4_P_TAG* D_8008EB08[2][4][8];
extern X4_P_TAG* D_80090D70[2][4][8];
extern struct X4_DrawInfo* D_8009B7A0;
#define M2C_UNK s32
extern M2C_UNK D_800CD3F0;
#define D_800CD3F0 (*(s8(*)[4]) & D_800CD3F0)

void func_80022E44(void) {
    u32 buffer;
    u32 i;
    u32 j;
    X4_OT_TYPE* otag;

    buffer = (*(s32*)(0x1F800000 + (0x000)));

    for (i = 0; i < 4; i++) {
        otag = &D_8009B7A0->ordering_table.start + D_800CD3F0[i];

        for (j = 0; j < 8; j++) {
            if (D_80090D70[buffer][i][j] != ((void*)0)) {
                (((X4_P_TAG*)(D_8008EB08[buffer][i][j]))->addr =
                     (X4_u_long)((X4_u_long)(((X4_P_TAG*)(otag))->addr)));
                (((X4_P_TAG*)(otag))->addr =
                     (X4_u_long)(D_80090D70[buffer][i][j]));
            }
        }
    }
}
#undef D_800CD3F0
