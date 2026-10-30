#include "common.h"
#define M2C_UNK s32
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
extern u8 D_800C4560;
extern s16 D_800F6BC4[16];

void func_800ED18C(s32 arg0, s32 arg1, u8* arg2) {
    u16* p;
    s32 n;
    s32 i;
    s32 base;
    s32 j;
    u16* src;
    u16* dst;
    s32 t;
    u32 c;
    s32 r;
    s32 g;
    s32 b;
    s32 dr;
    s32 dg;
    s32 db;
    u16 v;

    p = *(u16**)(arg2 + 0x20);
    n = *p;
    base = arg0;
    i = base % 15;
    base = (base / 15) * 15;
    p++;
    if (base == arg1) {
        for (i = 0; i < n; i++) {
            src = &p[n + (i << 5)];
            dst = (u16*)(SPAD28 + ((p[i] + 0x60) << 5));
            for (j = 0; j < 16; j++) {
                *dst++ = *src++;
            }
        }
        D_800C4560 |= 1;
        return;
    }
    for (; i < n; i += 15) {
        src = &p[n + (i << 5)];
        for (j = 0; j < 16; j++) {
            dst = src + 16;
            c = *src++;
            r = c & 0x1F;
            g = (c & 0x3E0) >> 5;
            b = (c & 0x7C00) >> 10;
            c = *dst;
            dr = c & 0x1F;
            dg = (c & 0x3E0) >> 5;
            db = (c & 0x7C00) >> 10;
            dr -= r;
            dg -= g;
            db -= b;
            t = ((arg1 - base) << 8) / arg1;
            v = (((t * dr) >> 8) + r) | ((((t * dg) >> 8) + g) << 5) |
                ((((t * db) >> 8) + b) << 10) | (c & 0x8000);
            if (v == 0 && c != 0) {
                v = 0x8000;
            }
            D_800F6BC4[j] = v;
        }
        load_palette(p[i] + 0x60, (M2C_UNK*)D_800F6BC4, 1);
    }
}
