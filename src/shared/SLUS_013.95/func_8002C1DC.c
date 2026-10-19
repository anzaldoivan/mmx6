#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

void func_8002C1DC(void) {
    s32 z;
    u8* p;
    s32 n;

    z = 0;
    p = (u8*)&D_800CCED0;
    n = 0x467;
    do {
        *p = z;
        p++;
    } while (n--);
}
