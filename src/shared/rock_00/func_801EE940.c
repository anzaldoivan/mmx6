#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0();
extern M2C_UNK D_800970A0;

void func_801EE940(void) {
    u8* p = (u8*)&D_800970A0;

    p[0x98]--;
    func_8002C9B0();
}
