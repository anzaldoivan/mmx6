#include "common.h"
#include "mmx6/x4.h"

void func_8001D218();
void func_80025F34();
s32 func_800280F4();
void func_80029B8C(void);
void func_800F02A0(u8, s8, s32, s16);
void func_800F0784(s32);
extern u8 D_80097427;
extern struct X4_EngineObj D_800CCED0;
#define ENG ((u8*)&D_800CCED0)

void func_800EAE98(u8* arg0) {
    u8* eng;
    func_8001D218();
    func_80029B8C();
    eng = ENG;
    func_800280F4();
    func_80025F34();
    eng[0x28] = 1;
    func_800F02A0(0x91, 1, 0x187, 0x18);
    arg0[3] = 4;
    func_800F0784(4);
    func_800F02A0(0x8C, 1, 0x108, 0x9E);
    func_800F02A0(0x8D, 1, 0x108, 0xB0);
    func_800F02A0(0xDB, 1, 0x1F2, 0xB0);
    func_800F02A0(0x8E, 1, 0x108, 0xBE);
    func_800F02A0(0x8F, 1, 0x108, 0xCC);
    func_800F02A0(0x90, 1, 0, 0);
    D_80097427 = 0;
    if ((u32)(eng[0x26] - 1) < 8U) {
        func_800F02A0(0xF8, 1, 0x140, 0x3C);
    } else {
        func_800F02A0(0xF9, 1, 0x140, 0x3C);
    }
    arg0[2]++;
}
#undef ENG
