#include "common.h"

extern s8 D_8008EF48[];
extern s32 D_800C1220[];

void* func_8002BBF4(void) {
    s8* p;

    for (p = D_8008EF48; p < D_8008EF48 + 0x30 * 0x9C; p += 0x9C) {
        if (*p == 0) {
            s8* q = p;
            s32 n = 0x9B;
            // !FAKE: keeps the quotient in the first return register so cse leaves the sign test and the +31 on it
            register s32 idx asm("$2");
            s32 m;
            s32 k;
            s32 bit;
            s32 t;

            do {
                *q++ = 0;
            } while (--n != -1);
            *(s32*)(p + 0x50) = 0;
            *(s32*)(p + 0x54) = 0;
            *(s32*)(p + 0x68) = 0;
            idx = (u32)(p - D_8008EF48) / 0x9C;
            t = idx;
            if (idx < 0) {
                t = idx + 0x1F;
            }
            bit = ~(1 << (idx & 0x1F));
            m = t >> 5;
            m *= 4;
            for (k = 0; k < 0x50; k++) {
                s32 off = k * 0xA4 + 0x98;
                *(s32*)((s8*)D_800C1220 + off + m) &= bit;
            }
            return p;
        }
    }
    return 0;
}
