#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9B0(); /* extern */
extern s8 D_800CCEEC;

void func_80053FE4(void) {
    D_800CCEEC = 1;
    ((M2C_UNK(*)())func_8002C9B0)();
}
