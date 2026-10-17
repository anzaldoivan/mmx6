#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
extern u8 D_8008EAFC;

void func_800F44A4(void* arg0) {
    if (D_8008EAFC == 0) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        *((u8*)arg0 + 6) += 1;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
