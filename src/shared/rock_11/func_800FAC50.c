#include "common.h"

s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s32 D_800FD484;
extern s32 D_800FD488;

void func_800FAC50(u8* arg0) {
    s32 m;

    arg0[3] = 1;
    *(s32**)(arg0 + 0x50) = &D_800FD484;
    *(s32**)(arg0 + 0x54) = &D_800FD488;
    m = func_80065A14(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x20) = (m * 2 + m) * 2;
    m = -func_80065944(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x24) = (m * 2 + m) * 2;
    arg0[6]++;
}
