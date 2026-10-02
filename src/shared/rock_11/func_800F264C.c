#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800F0050(s32); /* extern */
extern s8 D_800E4480;

void func_800F264C(s32 arg0) {
    D_800E4480 = 0;
    func_8003D330();
    func_800F0050(arg0);
}
