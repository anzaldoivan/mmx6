#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_80051E40(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;

    p->x_pos.val = arg0->x_pos.val;
    if (*((u8*)p + 0xE2) == 3) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
        *(s32*)((u8*)arg0 + 0x7C) = 0x28;
        arg0->unk5++;
    }
}
