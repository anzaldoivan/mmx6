#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800187A0(M2C_UNK);                   /* extern */
M2C_UNK func_80058734(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);     /* extern */
extern s8 D_800CD40C;
extern u8 D_800E2E14;
extern s32 D_800E2E18;
extern s16 D_800E2E48;
extern s32 D_800E2E4C;
extern s8 D_800E2E50;
extern s32 D_800E2E5C;

void func_800186A8(void) {
    s32 temp_s0;

    temp_s0 = D_800E2E5C;
    if (temp_s0 == 2) {
        D_800E2E14 = 0;
        func_800187A0(0);
        if (D_800E2E4C == temp_s0) {
            if (D_800E2E48 != 0) {
                do {

                } while (func_80064B44(9, 0, 0) == 0);
            }
        }
        func_80058734(0, 0, 0);
        D_800E2E4C = 0;
        D_800E2E50 = 1;
        D_800CD40C = 0;
        D_800E2E18 = 0;
    }
}
