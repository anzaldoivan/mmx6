#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

M2C_UNK func_8002C9B0();
void func_801EECA4(struct X4_WeaponObj* arg0) {
    if (arg0->unk2 == 0) {
        D_800970A0.shot_count--;
    }
    ((void (*)())func_8002C9B0)(arg0);
}
#undef D_800970A0
