#include "common.h"
#include "mmx6/x4.h"

void func_800F02A0(u8, s8, s32, s16);
void func_800F0784(s32);
extern s16 D_800F48F0;

#define ENG ((u8*)g_playthrough_state)
#define S_2 (((u8*)arg0)[0x2])
#define S_3 (((u8*)arg0)[0x3])
#define S_60 (((u8*)arg0)[0x60])

void func_800E98E0(void* arg0) {
    extern u8 g_playthrough_state[];
    u8* e = ENG;

    switch ((s8)e[0x27]) {
    case 0:
        if ((u32)(e[0x26] - 1) < 8U) {
            S_60 |= 1 << ((s8)e[0x26] - 1);
            func_800F02A0(0xF8, 2, 0x140, 0x3C);
        } else {
            func_800F02A0(0xF9, 2, 0x140, 0x3C);
        }
        func_800F02A0(0xF0, 2, 0x140, 0x9A);
        break;
    case 1:
        func_800F02A0(0xF7, 2, 0x140, 0x9A);
        if ((u32)(e[0x26] - 1) < 8U) {
            func_800F02A0(0xF8, 2, 0x140, 0x3C);
        } else {
            func_800F02A0(0xF9, 2, 0x140, 0x3C);
        }
        break;
    case 2:
        func_800F02A0(0xF7, 2, 0x140, 0x9A);
        if ((u32)(e[0x26] - 1) < 8U) {
            func_800F02A0(0xF8, 2, 0x140, 0x3C);
        } else {
            func_800F02A0(0xF9, 2, 0x140, 0x3C);
        }
        break;
    }
    func_800F02A0(0x91, 1, 0x1F, 0x18);
    S_3 = 0;
    func_800F0784(0);
    func_800F02A0(6, 2, 0xD2, 0x9A);
    func_800F02A0(7, 3, 0xD2, 0xA8);
    func_800F02A0(8, 4, 0xD2, 0xB6);
    func_800F02A0(9, 5, 0xD2, 0xC4);
    func_800F02A0(4, 6, 0xD2, 0xD2);
    func_800F02A0(0xF1, 3, 0x190, 0xA8);
    func_800F02A0(0xF2, 4, 0x190, 0xB6);
    func_800F02A0(0xF3, 5, 0x180, 0xC4);
    func_800F02A0(0xF4, 6, 0x1B0, 0xD2);
    D_800F48F0 = 6;
    {
        u8* f = ENG;
        f[0x28] = 1;
    }
    S_2++;
}

#undef ENG
#undef S_2
#undef S_3
#undef S_60
