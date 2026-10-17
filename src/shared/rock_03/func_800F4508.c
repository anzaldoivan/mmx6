#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80040488(M2C_UNK);
extern s8 D_800CCEF4;

void func_800F4508(u8* arg0) {
    if (*(s8*)(arg0 + 0x46) == 0) {
        func_800179A4(arg0, 0);
        func_80040488(0);
        D_800CCEF4 = 1;
        *(s16*)(arg0 + 0x7C) = 3;
        arg0[6] += 1;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
