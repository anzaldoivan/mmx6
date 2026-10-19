#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F117C(u16* arg0) {
    arg0[0x21] &= 0x7FFF;
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
