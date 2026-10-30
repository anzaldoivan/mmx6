#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_80097420;
extern u16 g_pad1_buttons[];

void func_800EB0CC(u8* arg0) {
    u8 cur;
    struct X4_EngineObj* eng = &D_80097420;
    s32 one;

    if (((s8*)eng)[4] != 0) {
        return;
    }
    one = 1;
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        cur = eng->unk7;
        if (cur == 0) {
            eng->unk7 = one;
        } else {
            eng->unk7 = cur - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        cur = eng->unk7;
        if (cur == one) {
            eng->unk7 = 0;
        } else {
            eng->unk7 = cur + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        func_800139F4(8);
        {
            // !FAKE: increment temp in the first return register
            register s32 t asm("$2") = arg0[2] + 1;
            arg0[2] = t;
        }
    }
}
