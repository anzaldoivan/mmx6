#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x8004FF4C get_reploid_status: returns the 4-bit status of rescue reploid arg0.
// basis: code src/shared/SLUS_013.95/func_80018F98.c:16 via=get_reploid_status
// callers: func_80018F98, func_8004E800, func_800EF6B0
s32 get_reploid_status(s32 arg0) {
    u8 a = arg0;
    u32 s = a & 7;
    // !FAKE: base pin schedules the table address before the index shift
    register u8* b asm("$3") = (u8*)&g_playthrough_state;

    b -= -((a >> 3) * 4);
    return (*(u32*)(b + 0xD8) >> (s * 4)) & 0xF;
}
