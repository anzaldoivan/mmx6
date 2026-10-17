#include "common.h"

extern s32 D_800C1220[];

void* func_8002C4C4(void) {
    s8* p;
    s8* end;
    s8* q;
    s32 k;

    p = (s8*)D_800C1220;
    end = p + 0x3340;
    if (p < end) {
        do {
            if (*p == 0) {
                q = p;
                k = 0xA3;
                do {
                    *q = 0;
                    k--;
                    q++;
                } while (k != -1);
                *(s32*)(p + 0x50) = 0;
                *(s32*)(p + 0x54) = 0;
                *(s32*)(p + 0x68) = 0;
                return p;
            }
            p += 0xA4;
        } while (p < end);
    }
    return 0;
}
