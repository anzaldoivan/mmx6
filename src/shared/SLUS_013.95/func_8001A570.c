#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

void func_8001A570(u8* arg0) {
    s32 v;
    s8 i;
    s8* p;

    i = (s8)arg0[2] / 3;
    p = (s8*)&D_800CCED0;
    v = __builtin_abs((p - -i)[0xD0]);
    arg0[3] = 1;
    arg0[0x47] = (v % 10) + 0x18;
}
