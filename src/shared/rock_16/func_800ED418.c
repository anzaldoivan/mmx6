#include "common.h"

extern s8 D_800CCEFC;
extern u8 D_800F1CC4[];
extern s8 D_800F1CCA[];

void func_800ED418(u8* arg0) {
    if (D_800CCEFC == 0) {
        D_800F1CCA[0] = 0;
        D_800F1CCA[1] = 0;
        D_800F1CC4[2] = 0;
        D_800F1CC4[3] = 0;
        arg0[2] -= 3;
    }
}
