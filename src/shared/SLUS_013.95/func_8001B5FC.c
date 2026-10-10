/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800192F8, AGPL-3.0; proven shared with X6 by exact signature 9577b76e9365 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_80064C94(M2C_UNK*, u32);
#define func_80064C94 ((int (*)(X4_CdlATV * vol)) func_80064C94)
extern u32 D_80070CC0;
extern M2C_UNK D_800E2F3C;
#define D_800E2F3C (*(X4_CdlATV*)&D_800E2F3C)
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)

M2C_UNK func_80058734(M2C_UNK, M2C_UNK, M2C_UNK);
void func_8001B5FC(void) {
    s32 temp_v0;
    s32 var_s0;

    ((void (*)())func_80058734)(0, 0, 0);
    if (D_800CC869 != 0) {
        var_s0 = D_80070CC0;
        if (var_s0 >= 0) {
            do {
                D_800E2F3C.val0 = var_s0;
                D_800E2F3C.val1 = 0;
                D_800E2F3C.val2 = var_s0;
                D_800E2F3C.val3 = 0;
                func_80064C94(&D_800E2F3C);
                var_s0 -= 2;
            } while (var_s0 >= 0);
        }
    } else {
        var_s0 = D_80070CC0;
        if (var_s0 >= 0) {
            do {
                temp_v0 = var_s0 / 2;
                D_800E2F3C.val0 = temp_v0;
                D_800E2F3C.val1 = temp_v0;
                D_800E2F3C.val2 = temp_v0;
                D_800E2F3C.val3 = temp_v0;
                func_80064C94(&D_800E2F3C);
                var_s0 -= 2;
            } while (var_s0 >= 0);
        }
    }
}
#undef D_800CC869
#undef D_800E2F3C
#undef func_80064C94
