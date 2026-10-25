#include "common.h"

#define SPAD (*(u8**)0x1F80004C)

s32 func_80017A04();
s32 func_800F82C0();

void func_800F6D18(u8* arg0) {
    u8* p;
    // !FAKE: depin: dropping it breaks the match (29/36)
    register u16 t asm("$2");

    p = SPAD;
    if (*(s8*)(p + 0x89) == 0) {
        *(s8*)(p + 0x89) = 0x78;
    }
    func_80017A04(arg0);
    func_800F82C0(arg0);
    t = *(u16*)(arg0 + 0x7C);
    *(u16*)(arg0 + 0x7C) = t + 1;
    if ((s16)t >= 0x3C) {
        *(u16*)(arg0 + 0x7C) = 0;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0xFFFC0000;
        arg0[6]++;
    }
}
