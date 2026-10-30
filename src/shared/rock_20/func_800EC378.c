#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK reset_level();
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern u16 g_pad1_buttons[];

void func_800EC378(u8* arg0) {
    s32 one;
    u8 t;

    one = 1;
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        t = D_80097420.unk7;
        if (t == 0) {
            D_80097420.unk7 = one;
        } else {
            D_80097420.unk7 = t - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        t = D_80097420.unk7;
        if (t == one) {
            D_80097420.unk7 = 0;
        } else {
            D_80097420.unk7 = t + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        switch (D_80097427) {
        case 0:
            func_800139F4(8);
            {
                // !FAKE: depin: dropping it breaks the match (72/75)
                register s32 three asm("$2") = 3;
                // !FAKE: depin: dropping it breaks the match (72/75)
                register s32 k1 asm("$3") = 1;

                arg0[2] = three;
                arg0[3] = k1;
            }
            break;
        case 1:
            arg0[2] = 0;
            break;
        }
    }
}
