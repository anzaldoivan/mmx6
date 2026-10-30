#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A494(s8* arg0) {
    s8 q;
    s32 v;

    q = arg0[2] / 3;
    {
        s32 k = 0xD0;
        v = ((s8*)&g_playthrough_state - -q)[k];
    }
    if (q != 0) {
        v = -v;
    }
    if (v < 0) {
        arg0[0x47] = 0x24;
        arg0[3] = 1;
        return;
    }
    arg0[3] = 0;
}
