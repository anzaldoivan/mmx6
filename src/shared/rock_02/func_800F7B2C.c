#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

#define SPAD4C (*(u8**)0x1F80004C)

void func_800F7B2C(u8* arg0) {
    if (SPAD4C[0x8A] != 0x11) {
        arg0[5] = 0xE;
        arg0[6] = 0;
        return;
    }
    func_800179A4(arg0, 7);
    *(u16*)(arg0 + 0x7C) = 0;
    {
        register s32 t asm("$2") = arg0[6] + 1;
        arg0[6] = t;
    }
    {
        register u8* q asm("$3") = SPAD4C;
        q[0x88] = 0;
    }
}

#undef SPAD4C
