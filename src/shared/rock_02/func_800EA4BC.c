#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_800CCF38;

#define SPAD (*(u8**)0x1F80004C)

void func_800EA4BC(struct X4_MainObj* arg0) {
    // !FAKE: pin the arm constant to the first return register (regalloc swap with the field read)
    register s32 n asm("$2");
    s32 v;
    if (D_800CCF38 >= 2) {
        v = arg0->unk7C;
        n = 0xF;
    } else {
        v = arg0->unk7C;
        n = 0x1E;
    }
    if (v == n) {
        SPAD[0x83] = 2;
    }
    if (--arg0->unk7C == 0) {
        arg0->unk5 = 3;
        arg0->unk6 = 0;
    }
}

#undef SPAD
