/* Adapted from sozud/mmx4 @29b62af src/main/125BC.c:func_80021DBC, AGPL-3.0; proven shared with X6 by exact signature adb625a87261 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_FixedMatrix2 D_80071394[16];

void func_80021380(s16* arg0, s16* arg1, s32 arg2) {
    struct X4_FixedMatrix2* matrix;
    s16 x;
    s16 y;
    s32 product0;
    s32 product1;
    s32 product2;
    s32 product3;

    matrix = &D_80071394[arg2 & 0xFF];
    x = *arg0;
    y = *arg1;
    product0 = x * matrix->m00;
    product1 = y * matrix->m01;
    product2 = x * matrix->m10;
    product3 = y * matrix->m11;
    *arg0 = (product0 >> 8) + (product1 >> 8);
    *arg1 = (product2 >> 8) + (product3 >> 8);
}
