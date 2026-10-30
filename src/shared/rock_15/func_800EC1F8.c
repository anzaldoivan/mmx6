#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EC1F8(u8* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (18/23)
        register s32 d asm("$2") = *(u16*)(arg0 + 0x7C) - 1;
        *(s16*)(arg0 + 0x7C) = d;
        if ((d << 16) == 0) {
            set_animation(arg0, 5);
            {
                // !FAKE: depin: dropping it breaks the match (18/23)
                register s32 t asm("$2") = arg0[6];
                *(s16*)(arg0 + 0x7C) = 0x29;
                arg0[6] = t + 1;
            }
        }
    }
}
