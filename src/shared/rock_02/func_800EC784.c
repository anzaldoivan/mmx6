#include "common.h"
#define M2C_UNK s32

#define SELF ((u8*)arg0)
#define SPAD4C (*(u8**)0x1F80004C)

extern s16 D_800970AA;
extern s16 D_800FAE04[];

void func_800EC784(void* arg0) {
    u8* p;
    s16 lim;
    s16 y;
    s16 x;
    s32 d;
    s8 st;
    u8 c;

    if (*(s8*)(SELF + 0x67) == 0) {
        st = *(s8*)(SELF + 5);
        if (st != 4) {
            if (st != 5) {
                p = SPAD4C;
                lim = D_800FAE04[*(s8*)(p + 0x81)];
                if (*(s8*)(SELF + 2) == 3) {
                    c = p[0x89];
                    if (c == 0) {
                        SELF[5] = 4;
                        SELF[6] = 0;
                        return;
                    }
                    p[0x89] = c - 1;
                    return;
                }
                x = D_800970AA;
                y = *(s16*)(SELF + 0xA);
                d = x - y;
                if (d >= 0) {
                    if (lim >= d) {
                        goto store;
                    }
                    return;
                }
                if (lim < y - x) {
                    return;
                }
            store:
                SELF[5] = 4;
                SELF[6] = 0;
            }
        }
    }
}
#undef SELF
