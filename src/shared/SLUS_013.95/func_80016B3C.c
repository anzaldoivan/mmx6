#include "common.h"

void func_80055D74(s8);
void func_8005FD74(s32);
extern s8 D_80090D50[6];
extern s8 D_80090D64[];
extern s8 D_800E25E0[];
extern u8 D_800E25F8[];

void func_80016B3C(void) {
    s8 i;
    s32 j;
    u8* p;
    s8* q;
    s32 c;
    // !FAKE: depin: dropping either pin breaks the match (59/67, 63/67)
    register s32 t asm("$3");
    // !FAKE: depin: dropping either pin breaks the match (59/67, 63/67)
    register s32 u asm("$2");

    for (i = 0; (t = i, u = t < 6, u); i++) {
        if (D_80090D64[i] != -1) {
            func_80055D74(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    for (i = 0; (t = i, u = t < 6, u); i++) {
        if (D_80090D50[i] != -1) {
            func_8005FD74(D_80090D50[i]);
            D_80090D50[i] = -1;
        }
    }
    c = 0xFF;
    j = 5;
    p = D_800E25F8 + j;
    do {
        *p = c;
        j--;
        p--;
    } while (j >= 0);
    c = -1;
    j = 0x17;
    q = D_800E25E0 + j;
    do {
        *q = c;
        j--;
        q--;
    } while (j >= 0);
}
