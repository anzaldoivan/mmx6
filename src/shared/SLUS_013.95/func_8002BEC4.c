#include "common.h"

extern s8 D_800950A0[];
extern s8 D_80096400[];
extern u8 D_800964A0[];

s8* func_8002BEC4(s8* p, s32 dir) {
    s8* q;
    s32 i;

    if (dir == 0) {
        if (p == 0) {
            p = D_800950A0;
        } else {
            p += 0xA0;
        }
        for (; p < (s8*)D_800964A0; p += 0xA0) {
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
    } else {
        if (p == 0) {
            p = D_80096400;
        } else {
            if (p == D_800950A0) {
                return 0;
            }
            p -= 0xA0;
        }
        for (; p >= D_800950A0; p -= 0xA0) {
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
    }
    return 0;
}
