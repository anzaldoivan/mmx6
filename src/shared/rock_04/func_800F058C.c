#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_800F058C(u8* arg0) {
    s32 i;
    u8* p;

    i = 0xE;
    p = arg0 + 0x24;
    do {
        *p = 0;
        i -= 1;
        p -= 1;
    } while (i >= 0);
    {
        struct X4_EngineObj* e = &g_playthrough_state;
        ((u8*)e)[0x27] = 0;
    }
    *(s16*)(arg0 + 0x14) = 0;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
    arg0[4] = arg0[4] + 1;
}
