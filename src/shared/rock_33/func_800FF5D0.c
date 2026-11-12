#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_80100C40;
extern s16 D_80100C42;

void func_800FF5D0(u8* arg0) {
    if (D_80100C40 == 0) {
        func_800179A4(arg0, 0);
        func_80016C48(2, 0x27, arg0);
        D_80100C42 = 2;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6]++;
    }
}
