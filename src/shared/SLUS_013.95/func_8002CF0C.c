#include "common.h"

extern s8 D_8008EF48[];
extern s32 D_800C1220[];

void func_8002CF0C(s8* arg0) {
    s32 i;
    s32 j;
    s8* p;
    s32 idx;
    s32 mask;
    s32 off;
    s32 w;

    p = arg0;
    for (j = 0x9B; j != -1; j--) {
        *p++ = 0;
    }
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x54) = 0;
    *(s32*)(arg0 + 0x68) = 0;
    idx = (u32)(arg0 - D_8008EF48) / 156;
    w = idx / 32;
    mask = ~(1 << (idx & 0x1F));
    for (i = 0; i < 80; i++) {
        off = i * 0xA4 + 0x98;
        *(s32*)((u8*)D_800C1220 + off + w * 4) &= mask;
    }
}
