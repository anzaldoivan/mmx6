#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230();
void func_800EABF0(u8* arg0, s16 arg1, u8 arg2);
extern s16 D_800970AA;

void func_800EAA78(u8* arg0) {
    s16 x;
    s32 d;

    func_800179A4(arg0, 7);
    *(u16*)(arg0 + 0xE) = *(u16*)(SPAD + 0x84) - 0x1A;
    func_800EABF0(arg0, *(s16*)(SPAD + 0x84), 0x11);
    d = D_800970AA;
    x = *(s16*)(arg0 + 0xA);
    *(s32*)(arg0 + 0x20) = (d - x) << 11;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0x80000;
    *(s32*)(arg0 + 0x2C) = 0x8000;
    func_8002D230(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (36/39)
        register s32 t asm("$2") = arg0[6] + 1;
        arg0[6] = t;
    }
}
