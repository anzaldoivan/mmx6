#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B6B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s8 D_800CCEE0;

void func_800F5120(struct X4_MainObj* arg0) {
    // !FAKE: keeps 0x19 in the call's argument register for the stores
    register s32 k asm("$4");

    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x40);
    if (D_800970A0.hp != 0 && D_800970A0.nova_strike_active == 0) {
        D_800970A0.spike_immune = 1;
        D_800970A0.unk68 = 0;
        ((M2C_UNK(*)())func_80016C48)(2, 0x20, arg0, &D_800970A0);
        k = 0x19;
        arg0->unk7C = 0x7F;
        arg0->unk7E = k;
        arg0->invincibility_timer = k;
        arg0->unk42 &= 0x7FFF;
        arg0->unk5++;
        D_800CCEE0 = 1;
        func_8002B6B0(k);
    }
}

#undef D_800970A0
