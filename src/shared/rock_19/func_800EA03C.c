#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s8 D_800CCF08;

void func_800EA03C(s8* arg0) {
    s32 v = D_800CCF08;

    if (v == 1) {
        arg0[3] = v;
    } else {
        arg0[3] = 0;
    }
    func_80017A04();
}
