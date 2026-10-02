#include "common.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*);           /* extern */
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*); /* extern */
extern s8 D_800CD40C;
extern s32 D_800E2E18;
extern u8 D_800E2E40;

void func_80018838(void) {
    s8 temp_v0;

    temp_v0 = func_80064874(1, &D_800E2E40);
    if ((temp_v0 == 2) && !(D_800E2E40 & 0x40) &&
        (func_800648D4(0x1B, 0, &D_800E2E40) != 0)) {
        D_800CD40C = temp_v0;
        D_800E2E18 = (s32)temp_v0;
    }
}
