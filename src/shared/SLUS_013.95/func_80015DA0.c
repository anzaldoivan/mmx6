/* Adapted from sozud/mmx4 @29b62af src/main/3D88.c:func_80014968, AGPL-3.0; proven shared with X6 by exact signature 587b9efb8c19 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern short func_80060604(unsigned char*, unsigned long, short);
extern short func_80060884(short);
extern s8 D_80090D50[6];
extern u8 D_800DF998;
extern union X4_CdSectorBuffer D_800CF998;
extern struct X4_CdCompletionSlot D_800E01E8[16];
extern u32 D_800E01C8;

void func_80015DA0(void) {
    s16 temp_v0;
    u8 temp_s1;
    u32 var_s0;

    if (D_800E01E8[D_800DF998].transfer_pending != 0xFFFF) {
        while (!func_80060884(0))
            ;
    } else {
        D_800E01E8[D_800DF998].transfer_pending = 0;
    }

    temp_s1 = D_800E01E8[D_800DF998].callback_arg;
    var_s0 = MIN(0x800, D_800E01C8);
    temp_v0 = func_80060604(D_800CF998.sectors[D_800DF998], var_s0,
                            D_80090D50[temp_s1]);
    D_800E01C8 -= var_s0;
    if ((D_800E01C8 == 0) && (temp_v0 == D_80090D50[temp_s1])) {
        while (!func_80060884(0))
            ;
    }
}
