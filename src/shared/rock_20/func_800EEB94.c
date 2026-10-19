#include "common.h"

extern s8 D_80097424[];
#define D_80097424 (*(s8*)&D_80097424)
extern u8 D_800F366C[];

void func_800EEB94(u8* arg0) {
    u16* p;
    u16* t;
    u16 v;
    if (D_80097424 == 0) {
        p = (u16*)(D_800F366C + 0x1282);
        *p = 0;
        p = 0;
        t = (u16*)(D_800F366C + 0x44);
        v = t[(D_80097424 << 24) >> 31];
        t = 0;
        *(u16*)(D_800F366C + 0x1280) = v;
        arg0[2]++;
    }
}
#undef D_80097424
