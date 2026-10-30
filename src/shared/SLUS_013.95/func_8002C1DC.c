#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8002C1DC(void) {
    s32 z;
    u8* p;
    s32 n;

    z = 0;
    p = (u8*)&g_playthrough_state;
    n = 0x467;
    do {
        *p = z;
        p++;
    } while (n--);
}
