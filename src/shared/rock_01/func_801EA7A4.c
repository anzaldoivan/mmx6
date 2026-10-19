#include "common.h"

extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern s32 D_801EF974[];

void func_801EA7A4(u8* self) {
    s16* a;
    s16* b;
    s16* c;
    s8* p;
    s8* q;
    s8* r;
    u32 v;
    s32 t;
    s32 i;

    a = &D_800CF854;
    v = (u16)a[1];
    if (v < 0x1F) {
        b = &D_80097430;
        c = &D_80090D5C;
        t = v + 2;
        a[1] = t;
        b[1] += 0x40;
        c[1] += 0x800;
        if ((u16)t >= 0x1F) {
            a[1] = 0x1F;
            b[1] = 0x3E0;
            c[1] = 0x7C00;
            self[6]++;
            for (i = 0; i < 16; i++) {
                D_801EF974[i] = D_80090C90[i + 16];
                D_80090C90[i + 16] = -1;
            }
            p = &D_80090D56;
            q = &D_8009742C;
            r = &D_800CF850;
            p[1] = 0;
            q[1] = 0;
            r[1] = 0;
            self[0xE1] = 0;
        }
    }
}
