#include "common.h"
#define M2C_UNK s32

void func_800187A0(s32 arg0);
extern u8 D_800E2E14;

M2C_UNK func_80018524(u8 arg0) {
    D_800E2E14 = arg0;
    func_800187A0(arg0);
}
