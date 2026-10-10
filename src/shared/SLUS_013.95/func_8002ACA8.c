#include "common.h"

extern s32 D_80090C90[][16];
#define D_80090C90 (*(s32(*)[]) & D_80090C90)
extern s8 D_80090D56;
#define D_80090D56 (*(u8*)&D_80090D56)
extern s16 D_80090D5C;
extern s8 D_8009742C;
#define D_8009742C (*(u8*)&D_8009742C)
extern s16 D_80097430;
extern u16 D_80097754;
extern u16 D_80097798[];
extern u16 D_800A21B6;
extern u8 D_800C4560;
extern u16 D_800C8858;
extern s8 D_800CF850;
#define D_800CF850 (*(u8*)&D_800CF850)
extern s16 D_800CF854;

#define SCRATCH_PAL (*(u16**)0x1F800028)

void func_8002ACA8(void) {
    u16* dst;
    u16* src;
    u32 i;
    u32 j;
    s32 mask;
    u16 c;
    u32 r;
    u32 g;
    u32 b;
    u32 lim;

    if (((D_800CF854 | D_80097430 | D_80090D5C) != 0) || (D_800C4560 & 4)) {
        if ((D_80097754 != (u16)D_800CF854) ||
            (D_800C8858 != (u16)D_80097430) ||
            (D_800A21B6 != (u16)D_80090D5C) || (D_800C4560 != 0)) {
            dst = D_80097798;
            i = 0;
            src = SCRATCH_PAL;
            do {
                if ((i & 0x1F) == 0) {
                    mask = D_80090C90[i >> 5];
                }
                if (mask < 0) {
                    j = 0;
                    do {
                        c = *src++;
                        if (c == 0) {
                            *dst = 0;
                        } else {
                            if (D_800CF850) {
                                lim = (u16)D_800CF854;
                                r = 0;
                                if ((c & 0x1F) >= lim) {
                                    r = (c & 0x1F) - lim;
                                }
                            } else {
                                r = (c & 0x1F) + (u16)D_800CF854;
                                if (r >= 0x20) {
                                    r = 0x1F;
                                }
                            }
                            if (D_8009742C) {
                                lim = (u16)D_80097430;
                                g = 0;
                                if ((c & 0x3E0) >= lim) {
                                    g = (c & 0x3E0) - lim;
                                }
                            } else {
                                g = (c & 0x3E0) + (u16)D_80097430;
                                if (g >= 0x3E1) {
                                    g = 0x3E0;
                                }
                            }
                            if (D_80090D56) {
                                lim = (u16)D_80090D5C;
                                b = 0;
                                if ((c & 0x7C00) >= lim) {
                                    b = (c & 0x7C00) - lim;
                                }
                            } else {
                                b = (c & 0x7C00) + (u16)D_80090D5C;
                                if (b >= 0x7C01) {
                                    b = 0x7C00;
                                }
                            }
                            *dst = r | g | b | (c & 0x8000);
                        }
                        j++;
                        dst++;
                    } while (j < 0x10);
                } else {
                    j = 0;
                    do {
                        *dst++ = *src++;
                        j++;
                    } while (j < 0x10);
                }
                mask <<= 1;
                i++;
            } while (i < 0x200);
            D_800C4560 = 2;
            D_80097754 = D_800CF854;
            D_800C8858 = D_80097430;
            D_800A21B6 = D_80090D5C;
        }
    }
}

#undef D_80090C90
#undef D_80090D56
#undef D_8009742C
#undef D_800CF850
