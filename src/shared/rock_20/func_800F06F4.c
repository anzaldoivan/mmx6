#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

s32 func_800F06F4(s32 arg0) {
    u8 a = arg0;
    u32 s = a & 7;
    // !FAKE: base pin schedules the table address before the index shift
    register u8* b asm("$3") = (u8*)&D_800CCED0;

    b -= -((a >> 3) * 4);
    return (*(u32*)(b + 0x118) >> (s * 4)) & 0xF;
}
