#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void func_800EC574(void* arg0);

void func_800EC254(u8* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match
        register s32 d asm("$2") = *(u16*)(arg0 + 0x7C) - 1;
        *(s16*)(arg0 + 0x7C) = d;
        if ((d << 16) == 0) {
            func_800EC574(arg0);
            {
                s32 t = arg0[6];
                *(s16*)(arg0 + 0x7C) = 0x3C;
                arg0[6] = t + 1;
            }
        }
    }
}
