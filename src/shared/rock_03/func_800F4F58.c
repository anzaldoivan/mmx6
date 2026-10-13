#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4F58(struct X4_MainObj* arg0) {
    if (D_800F7E0C == 0) {
        func_800179A4(arg0, 0);
        func_80016C48(2, 0x27, arg0);
        D_800F7E0E = 5;
        arg0->unk7C = 0;
        *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
    }
}
