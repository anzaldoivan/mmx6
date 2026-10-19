#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s16 D_800970AA;
extern s8 D_8009724F;
extern void (*D_800FB72C[])(void*);

void func_800EBC6C(s8* arg0) {
    D_800FB72C[arg0[6]](arg0);
    if (D_800970AA >= 0x1681) {
        arg0[4] = 2;
        func_80016C48(5, 3, arg0);
        D_8009724F = 0;
    }
}
