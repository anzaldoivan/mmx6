#include "common.h"

extern u32* D_8008EC18[2][102];
#define D_8008EC18 (*(u32 * (*)[2][6][17]) & D_8008EC18)
extern u32 D_80090E78[2][6][17];

void func_80026E20(s32 arg0) {
    u32** a;
    u32** b;
    u32* c;
    u32* d;
    u32* e;
    u32* f;
    u32* g;
    u32* h;
    s32 l;
    u32* base;
    u32 i;

    i = 0;
    l = arg0 + 3;
    base = (u32*)D_80090E78;
    h = &base[l * 17 + 102];
    b = D_8008EC18[0][l];
    d = base + l * 17;
    g = d;
    f = &base[arg0 * 17 + 102];
    a = D_8008EC18[0][arg0];
    c = base + arg0 * 17;
    e = c;
    do {
        a[0] = e;
        a[102] = f;
        b[102] = h;
        h++;
        b[0] = g;
        b++;
        g++;
        c[0] = 0;
        c[102] = 0;
        d[0] = 0;
        d[102] = 0;
        d++;
        f++;
        a++;
        e++;
        i++;
        c++;
    } while (i < 17);
}
#undef D_8008EC18
