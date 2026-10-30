#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK reset_level();
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern struct X4_EngineObj D_80097420;
extern u16 g_pad1_buttons[];

void func_800EC1F4(u8* arg0) {
    s32 one;
    u8 v;
    u8 t;
    s32 r;

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
        v = D_80097420.unk7;
        switch (v) {
        case 0:
            func_800139F4(8);
            r = 3;
            arg0[2] = r;
            arg0[3] = 0;
            break;
        case 1:
            func_800F02A0(0x95, 1, 0x11C, 0x40);
            func_800F0324(0xBC, 1, 0x16C, 0x80, 0);
            func_800F0324(0xC1, 1, 0x16C, 0xA0, v);
            func_800F02A0(0xB9, 1, 0, 0);
            D_80097420.unk7 = v;
            r = 2;
            arg0[2] = r;
            arg0[3] = 0;
            break;
        }
    }
}
