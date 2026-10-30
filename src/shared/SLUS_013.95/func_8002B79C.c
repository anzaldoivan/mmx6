#include "common.h"

extern s8 g_enemies[];
extern u8 g_projectiles[];

void func_8002B79C(void) {
    s8 z;
    u32 i;
    s8* p;
    s8* q;
    s32 k;

    z = 0;
    for (i = 0; i < 0x30; i++) {
        p = &g_enemies[i * 0x9C];
        if (p[1] != 0x2F) {
            q = p;
            k = 0x9C;
            while (k--) {
                *q++ = z;
            }
        }
    }
    for (i = 0; i < 0x20; i++) {
        q = (s8*)g_projectiles + i * 0xA0;
        k = 0xA0;
        while (k--) {
            *q++ = z;
        }
    }
}
