#include "common.h"
#include "mmx6/x4.h"

void func_800F02A0(u8, s8, s32, s16);
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F366C[];

void func_800EEF84(u8* arg0) {
    u8* p;
    s8* e;
    s32 i;

    p = D_800F366C + 0x70;
    e = (s8*)&D_800CCED0;
    i = e[0x26] + 7;
    func_800F02A0(p[i * 3], 2, 0x48, 0x9A);
    func_800F02A0((p - -((e[0x26] + 7) * 3))[1], 2, 0xDC, 0x9A);
    p = 0;
    *(s16*)(D_800F366C + 0x1284) = 2;
    e[0x28] = 1;
    arg0[2]++;
}
