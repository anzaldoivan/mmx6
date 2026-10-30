#include "common.h"
#include "mmx6/x4.h"

extern u8 g_projectiles[];

s32 check_attack_hit(void* arg0, void* arg1, s16* arg2, s16* arg3);

s8 func_80032BE8(struct X4_PlayerObj* arg0) {
    s8* p;
    s8 r;

    r = 0;
    for (p = (s8*)g_projectiles; p < (s8*)g_projectiles + 0x1400; p += 0xA0) {
        if (p[0] != 0 && check_attack_hit(p, arg0, (s16*)(p + 0x80),
                                          (s16*)(p + 0x82)) != 0) {
            r = p[1];
            p[0x70] |= 0xF;
        }
    }
    return r;
}
