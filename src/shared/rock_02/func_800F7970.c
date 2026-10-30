#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();
#define SPAD4C (*(u8**)0x1F80004C)

void func_800F7970(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (31/37)
        register s32 t asm("$2") = *(u16*)(arg0 + 0x7C);
        s32 n = t + 1;
        *(u16*)(arg0 + 0x7C) = n;
        if ((s16)t >= 0x3C) {
            *(u16*)(arg0 + 0x7C) = 0;
            set_animation(arg0, 9);
            {
                // !FAKE: depin: dropping it breaks the match (18/37)
                register s32 v asm("$2") = arg0[6] + 1;
                arg0[6] = v;
            }
            return;
        }
    }
    if (SPAD4C[0x8A] != 0x11) {
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (20/37)
            register s32 v asm("$2") = 5;
            arg0[6] = v;
        }
    }
}
