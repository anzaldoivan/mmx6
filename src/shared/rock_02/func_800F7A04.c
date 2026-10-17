#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK func_800F82C0(void* arg0);

void func_800F7A04(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (19/22)
        register u8* sp asm("$2") = SPAD4C;
        s32 b = sp[0x8A];
        // !FAKE: depin: dropping it breaks the match (19/22)
        register s32 k asm("$3") = 0x11;

        if (b == k) {
            return;
        }
    }
    {
        *(s16*)(arg0 + 0x7C) = 0x3C;
        arg0[6] = arg0[6] + 1;
    }
}

#undef SPAD4C
