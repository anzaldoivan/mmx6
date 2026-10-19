#include "common.h"

extern s8 D_8008EF48[];
extern u8 D_80093C98[];

void func_8002B79C(void) {
    s8 z;
    u32 i;
    s8* p;
    s8* q;
    s32 k;

    z = 0;
    for (i = 0; i < 0x30; i++) {
        p = &D_8008EF48[i * 0x9C];
        if (p[1] != 0x2F) {
            q = p;
            k = 0x9C;
            while (k--) {
                *q++ = z;
            }
        }
    }
    for (i = 0; i < 0x20; i++) {
        q = (s8*)D_80093C98 + i * 0xA0;
        k = 0xA0;
        while (k--) {
            *q++ = z;
        }
    }
}
