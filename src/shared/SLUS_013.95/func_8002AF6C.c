#include "common.h"

extern s32 D_80090C90[][16];
extern s16 D_80090D5C;
#define D_80090D5C ((u16*)&D_80090D5C)
extern s16 D_80097430;
#define D_80097430 ((u16*)&D_80097430)
extern u16 D_80097798[];
extern u16 D_8009E1B0[];
extern u8 D_800C4560;
extern s8 D_800CF850;
#define D_800CF850 ((u8*)&D_800CF850)
extern s16 D_800CF854;
#define D_800CF854 ((u16*)&D_800CF854)
#define PAL_SRC (*(u16**)0x1F800028)

void func_8002AF6C(s32 arg0, s32 mask) {
    u16* src;
    u16* dst;
    u32 i;
    u32 j;
    u32 r;
    u32 g;
    u32 b;
    u16 c;
    u16 out;

    if (D_800C4560 == 2) {
        src = D_80097798;
    } else if (D_800C4560 == 8) {
        src = D_8009E1B0;
    } else {
        src = PAL_SRC;
    }
    dst = D_8009E1B0;
    D_800C4560 = 8;
    for (i = 0; i < 0x200; i++) {
        if (!(i & 0x1F)) {
            mask = D_80090C90[arg0][i >> 5];
        }
        j = 0;
        if (mask < 0) {
            if (D_800CF850[arg0] != 0) {
                u16* d = dst;
                u16* s = src;
                s32 num = D_800CF854[arg0];
                s32 k;

                if (num >= 0x1F) {
                    num = 0x1F;
                }
                if (num == 0x1F) {
                    for (k = 0; k < 16; k++) {
                        *d++ = 0;
                    }
                } else {
                    for (k = 0; k < 16; k++) {
                        c = *s++;
                        r = (c & 0x1F) << 8;
                        g = (c & 0x3E0) << 8;
                        b = (c & 0x7C00) << 8;
                        r = (r - r * num / 32) >> 8;
                        g = (g - g * num / 32) >> 8;
                        b = (b - b * num / 32) >> 8;
                        r &= 0x1F;
                        g &= 0x3E0;
                        b &= 0x7C00;
                        out = r | g | b | (c & 0x8000);
                        if (out == 0 && c != 0) {
                            out = 0x8000;
                        }
                        *d++ = out;
                    }
                }
                src += 16;
                dst += 16;
            } else {
                u32 r2;
                u32 g2;
                u32 b2;
                u16 c2;

                for (j = 0; j < 16; j++) {
                    c2 = *src++;
                    r2 = (c2 & 0x1F) + D_800CF854[arg0];
                    if (r2 > 0x1F) {
                        r2 = 0x1F;
                    }
                    g2 = (c2 & 0x3E0) + D_80097430[arg0];
                    if (g2 > 0x3E0) {
                        g2 = 0x3E0;
                    }
                    b2 = (c2 & 0x7C00) + D_80090D5C[arg0];
                    if (b2 > 0x7C00) {
                        b2 = 0x7C00;
                    }
                    if (r2 == 0x1F && g2 == 0x3E0 && b2 == 0x7C00) {
                        *dst = 0x7FFF;
                    } else if (r2 | g2 | b2) {
                        *dst = r2 | g2 | b2 | (c2 & 0x8000);
                    } else {
                        *dst = 0;
                    }
                    dst++;
                }
            }
        } else {
            for (j = 0; j < 16; j++) {
                *dst++ = *src++;
            }
        }
        mask <<= 1;
    }
}

#undef D_80090D5C
#undef D_80097430
#undef D_800CF850
#undef D_800CF854
#undef PAL_SRC
