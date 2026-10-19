#include "common.h"

extern u8 D_800F366C[];

s32 func_800F05AC(s32 arg0) {
    s32 i;
    u8* p;

    i = 0;
    p = D_800F366C + 0xA0;
    for (; i < 0x1A; i++, p += 0xC) {
        if (arg0 == *(s32*)p) {
            return (u8)i;
        }
    }
    return 0;
}
