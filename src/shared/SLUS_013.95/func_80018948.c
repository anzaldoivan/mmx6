#include "common.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*);      /* extern */
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*); /* extern */
extern u8 D_800A21B4;
extern s8 D_800E2E16;
extern s32 D_800E2E18;
extern u8 D_800E2E40;
extern s16 D_800E2E48;
extern s32 D_800E2E4C;

void func_80018948(void) {
    s32 temp_v0;

    temp_v0 = func_80064874(1, 0);
    if ((temp_v0 == 2) && (D_800E2E4C != 0) && (D_800A21B4 == 0) &&
        (func_800648D4(0x1B, 0, &D_800E2E40) != 0)) {
        D_800E2E48 = 0;
        D_800E2E18 = temp_v0;
        if (D_800E2E40 & 0x10) {
            D_800E2E16 = 1;
        }
    }
}
