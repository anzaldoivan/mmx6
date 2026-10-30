#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8001A4FC(u8* arg0) {
    // !FAKE: row base in the first return register
    register s8* b asm("$2");
    // !FAKE: idx in the first argument register
    register s32 i asm("$4");
    // !FAKE: value in the second return register
    register s32 v asm("$3");

    i = (s8)((s8)arg0[2] / 3);
    b = (s8*)&g_playthrough_state;
    b -= -i;
    v = b[0xD0];
    if (v < 0) {
        v = -v;
    }
    if (v >= 10) {
        arg0[0x47] = 0x19;
        arg0[3] = 1;
        return;
    }
    arg0[3] = 0;
}
