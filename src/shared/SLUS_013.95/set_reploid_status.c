#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x8004FF00 set_reploid_status: writes 4-bit status arg1 of rescue reploid arg0.
// basis: code src/shared/SLUS_013.95/rescue_reploid.c:37 via=set_reploid_status
// callers: func_8004EA78, func_8004FB60, rescue_reploid
void set_reploid_status(u8 arg0, s32 arg1) {
    u8* e;
    s32* p;
    s32 sh;
    s32 o;
    u8* q;

    arg1 &= 0xFF;
    e = (u8*)&g_playthrough_state;
    o = (arg0 >> 3) * 4;
    q = e + 0xD8;
    p = (s32*)(o + q);
    sh = (arg0 & 7) * 4;
    *p = (*p & ~(0xF << sh)) | (arg1 << sh);
}
