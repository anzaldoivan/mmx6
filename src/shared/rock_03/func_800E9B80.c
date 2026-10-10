#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EAB3C(u8* arg0, u8 arg1);
extern u8 D_800F70C4[];
#define SPAD4C (*(u8**)0x1F80004C)

void func_800E9B80(u8* arg0) {
    s8 t;

    func_80016C48(2, 6, arg0);
    *(u8**)(arg0 + 0x50) = SPAD4C + 0x80;
    t = arg0[2];
    *(u8**)(arg0 + 0x54) = SPAD4C + 0x80;
    if (t == 0) {
        func_800179A4(arg0, 2);
        SPAD4C[0x81] = 0x1A - D_800F70C4[(s8)arg0[0x45] - 1];
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
        func_800EAB3C(arg0, 0);
    } else if (t == 1) {
        func_800179A4(arg0, 0x10);
        ((s8*)SPAD4C)[0x81] = -0x1E;
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
        func_800EAB3C(arg0, 1);
    }
    arg0[6]++;
}

#undef SPAD4C
