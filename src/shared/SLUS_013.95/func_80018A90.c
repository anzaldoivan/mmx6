#include "common.h"

#define M2C_UNK s32

s8 func_80064874(M2C_UNK, u8*);           /* extern */
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*); /* extern */
s32 func_80064A10(M2C_UNK, M2C_UNK*);          /* extern */
extern M2C_UNK D_800E2E04;
extern s32 D_800E2E18;
extern s32 D_800E2E4C;
extern u8 D_800E2E60;

void func_80018A90(void) {
    s32 var_v0;

    if (func_80064874(1, 0) == 2) {
        if (D_800E2E60 == 0) {
            var_v0 = func_800648D4(0x15, &D_800E2E04, 0);
        } else {
            var_v0 = func_80064A10(0x15, &D_800E2E04);
        }
        if (var_v0 != 0) {
            D_800E2E18 = 1;
        }
        D_800E2E4C = 2;
    }
}
