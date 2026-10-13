#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800F72F8;
extern s32 D_800F72FC;

void func_800EBC50(u8* arg0) {
    arg0[0x60] = 4;
    arg0[0x5C] = 0;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[0x16] = 4;
    arg0[0x67] = 1;
    *(s32*)(arg0 + 0x54) = 0;
    func_800179A4(arg0, 7);
    {
        register s32 k asm("$2") = -0x3FFF;
        *(s32*)(arg0 + 0x24) = k;
    }
    arg0[4] = 1;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s32**)(arg0 + 0x50) = &D_800F72F8;
    *(s32**)(arg0 + 0x68) = &D_800F72FC;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
    arg0[3] = 0;
}
