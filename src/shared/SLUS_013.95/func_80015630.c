#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s8 func_80014D50();
void func_80055D74(s8);
s8 func_80055F94(void*, s8, s32);
void func_8005A3CC(s8, u32, s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
extern s8 D_80090D50[6];
extern s8 D_80090D64[];
extern u8 D_8009509C;
extern s32 D_800E01A8;
extern u8* D_800E01AC;
extern u32 D_800E01BC;
extern u8 D_800E01CD;
extern u8* D_800E0368;

void func_80015630(void) {
    s8* p;
    u32 i;
    s32 k;

    if (D_800E01CD != 0) {
        D_800E01CD = 0;
        D_800E01AC = D_800E0368;
    }
    if (func_80014D50() == -1) {
        func_800648B4(0);
        func_80064B44(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    if (D_800E01A8 == 0) {
        i = (D_800E01BC >> 8) & 0xFF;
        p = &D_80090D64[i];
        if (*p != -1) {
            func_80055D74(*p);
            *p = -1;
        }
        *p = func_80055F94(D_800E0368, D_80090D50[i], 6);
        for (k = 0; k < 6; k++) {
            func_8005A3CC(D_80090D64[i], (s16)k, 0x7F, 0x7F);
        }
    }
}
