#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

void func_800F3684(struct X4_MainObj* arg0) {
    // !FAKE: depin: dropping it breaks the match (12/17)
    register u8 v asm("$2");

    func_800F5488(arg0);
    func_800179A4(arg0, 4);
    v = arg0->unk6;
    arg0->unk7C = 0x3C;
    arg0->unk6 = v + 1;
}
