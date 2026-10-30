#include "common.h"

extern u8 D_80091298[];
extern u8 D_80093C28[];
extern u8 g_projectiles[];

s8* func_8002C6F0(s8* arg0, s32 arg1) {
    s8* p;
    s8* q;
    s32 n;

    if (arg1 == 0) {
        if (arg0 == 0) {
            p = (s8*)D_80091298;
        } else {
            p = arg0 + 0x70;
        }
        for (; (u32)p < (u32)g_projectiles; p += 0x70) {
            if (*p == 0) {
                q = p;
                for (n = 0x6F; n != -1; n--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    } else {
        if (arg0 == 0) {
            p = (s8*)D_80093C28;
        } else {
            if (arg0 == (s8*)D_80091298) {
                return 0;
            }
            p = arg0 - 0x70;
        }
        for (; (u32)p >= (u32)D_80091298; p -= 0x70) {
            if (*p == 0) {
                q = p;
                for (n = 0x6F; n != -1; n--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    }
    return 0;
}
