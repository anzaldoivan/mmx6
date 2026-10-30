#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 g_pad1_buttons[];

#define ENG_B(o) ((u8)D_80097420[o])
#define ENG_SB(o) (D_80097420[o])

void func_800EA76C(u8* arg0) {
    extern s8 D_80097420[];
    u8 v;

    if (ENG_SB(4) == 0) {
        s32 one = 1;
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            v = ENG_B(7);
            if (v == 0) {
                D_80097420[7] = one;
            } else {
                D_80097420[7] = v - 1;
            }
        } else if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            v = ENG_B(7);
            if (v == one) {
                D_80097420[7] = 0;
            } else {
                D_80097420[7] = v + 1;
            }
        }
        if (g_pad1_buttons[2] & 0x40) {
            play_sound(0, 0x22, 0);
            if (ENG_B(7) != 1) {
                func_800139F4(8);
            }
            arg0[1] += 2;
            *(s16*)(arg0 + 0xA) = ENG_B(7);
            return;
        }
        if (g_pad1_buttons[2] & 0x10) {
            func_800139F4(8);
            {
                // !FAKE: depin: dropping it breaks the match (80/85)
                register s32 b asm("$2") = arg0[1];
                *(s16*)(arg0 + 0xA) = 2;
                arg0[1] = b + 2;
            }
        }
    }
}
