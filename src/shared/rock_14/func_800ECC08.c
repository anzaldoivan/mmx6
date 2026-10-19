#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800ECC08(s8* arg0) {
    if (arg0[2] == 0) {
        func_800179A4(arg0, 1);
    } else {
        func_800179A4(arg0, 2);
    }
    ((u8*)arg0)[4] = ((u8*)arg0)[4] + 1;
}
