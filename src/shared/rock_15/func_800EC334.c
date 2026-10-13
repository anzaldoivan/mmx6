#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EC334(u8* arg0) {
    func_80017A04();
    func_800179A4(arg0, 6);
    {
        // !FAKE: depin: dropping it breaks the match (12/17)
        register s32 t asm("$2") = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0x1A;
        arg0[6] = t + 1;
    }
}
