#include "common.h"

extern s8 D_8008EF48[];
extern u8 D_80093C98[];

void func_8002C22C(void) {
    u32 i;
    s32 j;
    u8* p;
    u8 v;

    v = 0;
    for (i = 0; i < 48; i++) {
        p = (u8*)&D_8008EF48[i * 156];
        j = 155;
        do {
            *p++ = v;
        } while (j-- != 0);
    }
    for (i = 0; i < 32; i++) {
        p = &D_80093C98[i * 160];
        j = 159;
        do {
            *p++ = v;
        } while (j-- != 0);
    }
}
