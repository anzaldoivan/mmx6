#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F3F40(u8* arg0) {
    func_80017A04();
    ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 6);
    arg0[5] = 1;
    arg0[6] = 0;
}
