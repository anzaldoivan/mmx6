#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s8 D_800CCEDF;

void func_80037E1C(s8* arg0) {
    if (arg0[6] == 0) {
        ((void (*)())func_80017A04)();
        if (D_800CCEDF != 0) {
            arg0[6] = (u8)arg0[6] + 1;
        }
    } else {
        arg0[4] = 3;
        arg0[5] = 0;
        arg0[6] = 0;
    }
}
