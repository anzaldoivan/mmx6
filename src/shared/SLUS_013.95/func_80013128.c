#include "common.h"

extern s32 D_8006D9B0[];

void func_80013128(void) {
    u8* low = 0;
    u8* s;
    s32 buf;
    s32 off;
    s32* dst;
    s32* src;
    s32 i;
    s32 k;

    k = 0x40000404;
    buf = 0x801FEC00;
    off = 0xC0;
    s = (u8*)0x801F8100;
    for (i = 3; i >= 0; i--) {
        *(s16*)s = 0;
        *(s32*)(s + 0xC) = (s32)(*(u8**)(low + 0x110) + off);
        *(s32*)(s + 0x10) = buf;
        buf += 0x400;
        off += 0xC0;
        *(s32*)(*(s32*)(s + 0xC) + 0x94) = k;
        s[0x70] = 0;
        s += 0x80;
    }
    dst = (s32*)0x801F8000;
    src = D_8006D9B0;
    for (i = 8; i >= 0; i--) {
        *dst++ = *src++;
    }
}
