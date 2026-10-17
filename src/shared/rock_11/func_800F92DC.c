#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
extern u16 D_800FDA7E;

void func_800F92DC(struct X4_MainObj* arg0) {
    if ((s16)D_800FDA7E >= 0xA) {
        arg0->unk5 = 4;
        arg0->unk6 = 0;
        return;
    }
    func_800FA4C8(arg0);
    ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 7);
    arg0->unk6 = arg0->unk6 + 1;
}
