#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
M2C_UNK func_8002C9B0();

void func_801EE72C(struct X4_PlayerObj* arg0) {
    arg0->unk50 = 0;
    if (arg0->id != 0x15) {
        D_800970A0.shot_count--;
    }
    func_8002C9B0();
}
#undef D_800970A0
