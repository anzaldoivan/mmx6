#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_800F82C0(void* arg0);

void func_800F7E68(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (15/22)
        register s32 t asm("$2") = *(u16*)(arg0 + 0x7C);

        *(u16*)(arg0 + 0x7C) = t + 1;
        if ((s16)t < 0x79) {
            return;
        }
    }
    {
        arg0[5] = 0xB;
        arg0[6] = 0;
    }
}
