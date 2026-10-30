#include "common.h"

extern u8 g_projectiles[];

s8* func_8002C458(void) {
    s8* p;
    s8* q;
    s32 i;

    for (p = g_projectiles; p < g_projectiles + 0x1400; p += 0xA0) {
        if (*p == 0) {
            q = p;
            i = 0x9F;
            do {
                *q++ = 0;
                i--;
            } while (i != -1);
            *(s32*)(p + 0x50) = 0;
            *(s32*)(p + 0x54) = 0;
            *(s32*)(p + 0x68) = 0;
            return p;
        }
    }
    return 0;
}
