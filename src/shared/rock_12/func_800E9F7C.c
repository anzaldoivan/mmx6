#include "common.h"

#define M2C_UNK s32

M2C_UNK SsSepPlay(s8, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s8 D_80090D69;

void func_800E9F7C(void) {
    if (D_80090D69 != -1) {
        SsSepPlay(D_80090D69, 0, 1, 0);
    }
}
