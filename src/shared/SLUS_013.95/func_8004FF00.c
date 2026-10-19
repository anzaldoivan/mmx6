#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

void func_8004FF00(u8 arg0, s32 arg1) {
    u8* e;
    s32* p;
    s32 sh;
    s32 o;
    u8* q;

    arg1 &= 0xFF;
    e = (u8*)&D_800CCED0;
    o = (arg0 >> 3) * 4;
    q = e + 0xD8;
    p = (s32*)(o + q);
    sh = (arg0 & 7) * 4;
    *p = (*p & ~(0xF << sh)) | (arg1 << sh);
}
