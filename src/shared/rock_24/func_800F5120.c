#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B6B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_800CCEE0;

void func_800F5120(struct X4_MainObj* arg0) {
    // !FAKE: keeps 0x19 in the call's argument register for the stores
    register s32 k asm("$4");

    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x40);
    if (g_Player.hp != 0 && g_Player.nova_strike_active == 0) {
        g_Player.spike_immune = 1;
        g_Player.unk68 = 0;
        ((M2C_UNK(*)())play_sound)(2, 0x20, arg0, &g_Player);
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

#undef g_Player
