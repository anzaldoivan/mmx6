#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800F82C0();

void func_800F590C(struct X4_MainObj* arg0) {
    register s16 d asm("$2");

    func_800F82C0();
    d = arg0->unk7C - 1;
    arg0->unk7C = d;
    if (d == 0) {
        arg0->unk6 = 4;
    }
}
