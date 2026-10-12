#include "common.h"

s32 func_80017A04();
void* func_8002C458();

void func_800EDB00(u8* arg0) {
    s8 s;
    u8* o;

    func_80017A04();
    s = ((s8*)arg0)[0x45];
    if (s == 1) {
        o = func_8002C458();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x1B;
            o[2] = s;
            *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
            *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
            o[0x14] = arg0[0x14];
            *(s32*)(o + 0x8) = *(s32*)(arg0 + 0x8);
            *(s32*)(o + 0xC) = *(s32*)(arg0 + 0xC);
            *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
            o[0x15] = arg0[0x15];
            *(u8**)(o + 0x7C) = arg0;
        }
        arg0[6]++;
    }
}
