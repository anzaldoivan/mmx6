#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

void func_8003D014(void* arg0) {
    s8* p = arg0;
    // !FAKE: base register
    register s8* b asm("$2");

    if (p[0x8D] == 0) {
        b = (s8*)&D_800CCED0;
        {
            s32 i = p[2];
            b -= -i;
        }
        if (p[0x5C] < (s8)(b[0x5B] / 3)) {
            p[0x8D] = 0x78;
        }
    }
}
