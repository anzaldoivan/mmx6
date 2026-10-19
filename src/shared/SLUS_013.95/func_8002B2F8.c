#include "common.h"

extern s32 D_80090C90[][16];
extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

s32 func_8002B2F8(s32 arg0) {
    s32 i;
    s32 j;
    s32 o;

    o = arg0 * 2;
    *(s16*)(o + (s32)&D_80090D5C) = 0;
    *(s16*)(o + (s32)&D_80097430) = 0;
    *(s16*)(o + (s32)&D_800CF854) = 0;
    for (i = 0, j = 15; i < 16; i++, j--) {
        ((s32*)D_80090C90)[arg0 * 16 + j] = 0;
    }
    D_800C4560 |= 1;
}
