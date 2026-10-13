#include "common.h"

extern u8 D_800F7528[];
extern s32 D_800F77E4;

void func_800F02AC(void* arg0) {
    s32 v;
    s32 c;
    u8 i;
    s32 t;
    s32 m;

    v = *(s32*)((u8*)arg0 + 0x20);
    if (v < 0) {
        {
            // !FAKE: depin: dropping it breaks the match (61/68)
            register s32 x asm("$2") = *(s16*)((u8*)arg0 + 0xA);
            c = x < *(s16*)((u8*)arg0 + 0x88);
        }
        goto block_4;
    }
    if (v > 0) {
        c = *(s16*)((u8*)arg0 + 0xA) > *(s16*)((u8*)arg0 + 0x88);
    block_4:
        m = *(u16*)((u8*)arg0 + 0x88);
        if (c != 0) {
            *(s16*)((u8*)arg0 + 0xA) = m;
            *(s32*)((u8*)arg0 + 0x20) = 0;
        }
    }
    v = *(s32*)((u8*)arg0 + 0x24);
    if (v < 0) {
        c = *(s16*)((u8*)arg0 + 0xE) > *(s16*)((u8*)arg0 + 0x8A);
        goto block_10;
    }
    if (v > 0) {
        {
            // !FAKE: depin: dropping it breaks the match (61/68)
            register s32 x asm("$2") = *(s16*)((u8*)arg0 + 0xE);
            c = x < *(s16*)((u8*)arg0 + 0x8A);
        }
    block_10:
        m = *(u16*)((u8*)arg0 + 0x8A);
        if (c != 0) {
            *(s16*)((u8*)arg0 + 0xE) = m;
            *(s32*)((u8*)arg0 + 0x24) = 0;
        }
    }
    if (*(s32*)((u8*)arg0 + 0x20) == 0 && *(s32*)((u8*)arg0 + 0x24) == 0) {
        D_800F77E4 += 1;
        i = (*((u8*)arg0 + 0x87))++;
        t = D_800F7528[i + *((u8*)arg0 + 0x86) * 6];
        *((u8*)arg0 + 6) = 0;
        *((u8*)arg0 + 5) = t;
    }
}
