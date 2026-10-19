#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B838();
extern u8 D_80097427;
extern u16 D_800C4570;

void func_800EFDE4(u8* arg0) {
    if (D_800C4570 & 0x40) {
        func_80016C48(0, 0x22, 0);
        ((void (*)())func_8002B838)();
        D_80097427 = 0;
        arg0[1] = 0x14;
        arg0[2] = 0;
    }
}
