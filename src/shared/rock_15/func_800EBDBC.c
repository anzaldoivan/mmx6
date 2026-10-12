#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);

void func_800EBDBC(struct X4_MainObj* arg0) {
    if (--arg0->unk7C == 0) {
        func_8004E654((struct X4_BaseObj*)arg0, 0x14);
        arg0->state++;
        return;
    }
    if (--arg0->unk7E == 0) {
        ((void (*)(void*, s32, s32, s32))func_80049EBC)(arg0, 1, 0x20, 0x20);
        arg0->unk7E = 5;
    }
}
