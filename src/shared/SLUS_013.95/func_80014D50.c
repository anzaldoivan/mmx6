/* Adapted from sozud/mmx4 @29b62af src/main/3D88.c:func_800136B0, AGPL-3.0; proven shared with X6 by exact signature 630fc0e04ff1 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
int func_80064CB4(void* madr, int size);
int func_800617A4(X4_CdlLOC* p);
extern u8* D_800E01AC;
extern s32 D_800E01B4;
extern s32 D_800E01A8;
extern u8 D_800DF9A8[0x800];
extern X4_CdlLOC D_800E0388;

s8 func_80014D50(void) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    u32 temp_v0;
    u32 var_v0;

    if ((u32)D_800E01A8 >= 0x801U) {
        func_80064CB4(&D_800E0388, 3);
        temp_v0_2 = func_800617A4(&D_800E0388);
        if (temp_v0_2 == (D_800E01B4 + 1)) {
            D_800E01B4 = temp_v0_2;
            func_80064CB4(D_800E01AC, 0x200);
            temp_v0 = D_800E01A8 - 0x800;
            D_800E01A8 = temp_v0;
            D_800E01AC += 0x800;
        } else {
            return -1;
        }
    } else {
        func_80064CB4(&D_800E0388, 3);
        temp_v0_3 = func_800617A4(&D_800E0388);
        if (temp_v0_3 != (D_800E01B4 + 1)) {
            return -1;
        }
        D_800E01B4 = temp_v0_3;
        func_80064CB4(D_800E01AC, ((u32)(D_800E01A8 + 3) >> 2));
        var_v0 = (u32)(D_800E01A8 + 3) >> 2;
        if (var_v0 != 0x200) {
            var_v0 = func_80064CB4(&D_800DF9A8, 0x200 - var_v0);
        }
        D_800E01A8 = 0;
    }
}
