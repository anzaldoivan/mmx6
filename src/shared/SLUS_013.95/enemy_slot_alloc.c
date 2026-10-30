#include "common.h"

extern s8 g_enemies[];
extern s32 D_800C1220[];

// 0x8002BBF4 enemy_slot_alloc: first free 0x9C slot of the enemy object array g_enemies[48], cleared; returns it or 0.
// basis: xref objects.tsv:338 (origin type 0/1, 7 frames)
// callers: drop_item, func_8004FF7C, func_80050250; 33 in overlays rock_02/03/04/05/07/08/09/10/11/15/22/45
void* enemy_slot_alloc(void) {
    s8* p;

    for (p = g_enemies; p < g_enemies + 0x30 * 0x9C; p += 0x9C) {
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
            idx = (u32)(p - g_enemies) / 0x9C;
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
