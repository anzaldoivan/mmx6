#include "common.h"

extern s32 D_80090C90[][16];
#define D_80090C90 (*(s32(*)[]) & D_80090C90)
extern s8 D_80090D56;
#define D_80090D56 (*(u8*)&D_80090D56)
extern s16 D_80090D5C;
extern s8 D_8009742C;
#define D_8009742C (*(u8*)&D_8009742C)
extern s16 D_80097430;
extern s8 D_800CF850;
#define D_800CF850 (*(u8*)&D_800CF850)
extern s16 D_800CF854;

u32 func_80025248(u16 arg0) {
    s32 r;
    s32 g;
    s32 b;
    u32 v;
    u32 x;

    if (D_80090C90[0] & 0xC000) {
        v = (u16)D_800CF854;
        x = v | (u16)D_80097430;
        if (((u16)D_80090D5C | x) != 0) {
            v &= 0xFFFF;
            if ((v == ((u16)D_80097430 >> 5)) &&
                (v == ((u16)D_80090D5C >> 10))) {
                if (D_800CF850 != 0) {
                    r = 0;
                    if ((arg0 & 0x1F) >= v) {
                        r = (arg0 & 0x1F) - (u16)D_800CF854;
                    }
                } else {
                    r = (arg0 & 0x1F) + (u16)D_800CF854;
                    if (r >= 0x20) {
                        r = 0x1F;
                    }
                }
                if (D_8009742C != 0) {
                    g = 0;
                    if ((arg0 & 0x3E0) >= (u16)D_80097430) {
                        g = (arg0 & 0x3E0) - (u16)D_80097430;
                    }
                } else {
                    g = (arg0 & 0x3E0) + (u16)D_80097430;
                    if (g >= 0x3E1) {
                        g = 0x3E0;
                    }
                }
                if (D_80090D56 != 0) {
                    if ((arg0 & 0x7C00) >= (u16)D_80090D5C) {
                        b = (arg0 & 0x7C00) - (u16)D_80090D5C;
                    } else {
                        b = 0;
                    }
                } else {
                    b = (arg0 & 0x7C00) + (u16)D_80090D5C;
                    if (b >= 0x7C01) {
                        b = 0x7C00;
                    }
                }
                arg0 = (r | g | b | (arg0 & 0x8000));
            }
        }
    }
    return arg0;
}

#undef D_80090C90
#undef D_80090D56
#undef D_8009742C
#undef D_800CF850
