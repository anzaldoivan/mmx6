#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_80078E48[];
extern u8 D_800CD40C;

void func_80051AC8(s8* arg0) {
    if (D_800CD40C == 2) {
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))func_80021760)(
            D_80078E48[arg0[2]], 0xFF, 0);
        arg0[5]++;
    }
}
