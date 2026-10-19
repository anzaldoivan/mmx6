#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
extern s16 D_800F7E10;
extern s16 D_800F7E20[];

void func_800F56B4(struct X4_MainObj* arg0) {
    D_800F7E20[arg0->ext.main_33.unk88] = 0;
    D_800F7E10--;
    ((M2C_UNK(*)())func_8002C9B0)(arg0, D_800F7E20);
}
