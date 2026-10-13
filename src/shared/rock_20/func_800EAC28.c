#include "common.h"
#include "mmx6/x4.h"

void func_800EE6F4(u8* arg0);
void func_8001BD40();
void func_800F02A0(u8, s8, s32, s16);
void func_800F0784(s32);
extern u8 D_80097427;

void func_800EAC28(u8* arg0) {
    extern u8 D_800CCED0[];
    u8* e;

    if ((s8)D_800CCED0[0x27] == 1) {
        s32 v = *(u16*)(D_800CCED0 + 0x6A) & 0x8000;
        if (v != 0) {
            v = 4;
        } else {
            v = 2;
        }
        arg0[0x39] = v;
    }
    e = D_800CCED0;
    if (*(s16*)(e + 0xD2) >= 0x270F) {
        *(s16*)(e + 0xD2) = 0x270F;
    }
    if (*(s16*)(e + 0xD4) >= 0x270F) {
        *(s16*)(e + 0xD4) = 0x270F;
    }
    func_800EE6F4(arg0);
    func_8001BD40();
    e[0x28] = 1;
    arg0[3] = 4;
    func_800F0784(4);
    func_800F02A0(0x8C, 1, 0x108, 0x9E);
    func_800F02A0(0x8D, 1, 0x108, 0xB0);
    func_800F02A0(0xDB, 1, 0x1F2, 0xB0);
    func_800F02A0(0x8E, 1, 0x108, 0xBE);
    func_800F02A0(0x8F, 1, 0x108, 0xCC);
    func_800F02A0(0x90, 1, 0, 0);
    D_80097427 = 0;
    arg0[2]++;
}
