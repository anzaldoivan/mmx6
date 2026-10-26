#include "common.h"

void SsInit();
void SsSetTableSize(void*, s32, s32);
void SsSetTickMode(s32);
void SsUtSetReverbType(s32);
extern s8 D_80090D50[6];
extern s8 D_80090D64[];
extern u8 D_800E1550;
extern s32 D_800E1560;
extern s8 D_800E25E0[];
extern u8 D_800E25F8[];

void func_80016950(void) {
    u8 i;

    D_800E1550 = 0;
    for (i = 0; i < 6; i++) {
        D_80090D50[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        D_80090D64[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        D_800E25F8[i] = 0xFF;
    }
    for (i = 0; i < 0x18; i++) {
        D_800E25E0[i] = -1;
    }
    SsInit();
    SsSetTableSize(&D_800E1560, 3, 8);
    SsSetTickMode(1);
    SsUtSetReverbType(0);
}
