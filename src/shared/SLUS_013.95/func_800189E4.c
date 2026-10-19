#include "common.h"
#define M2C_UNK s32

void func_800187A0(s32 arg0);
M2C_UNK func_80058734(M2C_UNK, M2C_UNK, M2C_UNK);
s8 func_80064874(M2C_UNK, u8*);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
extern u8 D_800E2E14;
extern s32 D_800E2E18;
extern s32 D_800E2E4C;

void func_800189E4(void) {
    s32 temp_v0;

    temp_v0 = func_80064874(1, 0);
    if (temp_v0 == 2) {
        if (D_800E2E4C == temp_v0) {
            if (func_80064B44(9, 0, 0) != 0) {
                func_80058734(0, 0, 0);
                D_800E2E14 = 0;
                func_800187A0(0);
                D_800E2E4C = 0;
                D_800E2E18 = 0;
            }
        } else {
            func_80058734(0, 0, 0);
            D_800E2E14 = 0;
            func_800187A0(0);
            D_800E2E18 = 0;
        }
    }
}
