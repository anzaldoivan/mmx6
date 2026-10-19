#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_80021194(struct X4_AnimatedObj* arg0, s8* arg1) {
    s32 var_v1;
    s8 temp_a2;

    temp_a2 = arg0->unk2;
    var_v1 = 1;
    if (temp_a2 == 0) {
        var_v1 = 2;
    }
    if ((arg1[0x9B] == var_v1) || (arg1[0x9C] == var_v1)) {
        arg0->on_screen = 1;
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, temp_a2 + 8);
        arg0->state++;
    }
}
