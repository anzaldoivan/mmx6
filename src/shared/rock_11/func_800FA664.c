#include "common.h"

s32 func_8002D654(s8*, u8*);
extern u8 D_80093C98[];

s32 func_800FA664(u8* arg0) {
    s8* p;

    for (p = (s8*)D_80093C98; p < (s8*)D_80093C98 + 0x1400; p += 0xA0) {
        if (p[0] != 0 && p[1] == 0x19 && !(p[2] & 0xF0) &&
            func_8002D654(p, arg0) != 0) {
            if (p[4] == 1 && p[0x98] == 0) {
                *(s32*)(p + 0x84) = p[4];
                return 1;
            }
        }
    }
    return 0;
}
