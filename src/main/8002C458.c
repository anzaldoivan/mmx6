#define func_8002C32C func_8002C458
#define D_800950A0 g_projectiles
#include "common.h"

#include "mmx6/projectile.h"

s8* func_8002C458(void) {
    s8* p;
    s8* q;
    s32 i;

    for (p = (s8*)g_projectiles; p < (s8*)g_projectiles + 0x1400; p += 0xA0) {
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
#undef func_8002C32C
#undef D_800950A0
