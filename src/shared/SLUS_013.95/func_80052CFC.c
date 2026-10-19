#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0(); /* extern */
extern s32 D_8008EC0C;
extern s16 D_8009741A;

void func_80052CFC(s32 arg0) {
    D_8008EC0C = 1;
    D_8009741A = 0x3C;
    ((M2C_UNK(*)())func_8002C9B0)(arg0);
}
