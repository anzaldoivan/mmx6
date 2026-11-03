#include "common.h"

#include "psyq/libsnd.h"
#include "mmx6/globals.h"
extern u8 D_800E1550;
extern s32 D_800E1560;

void func_80016950(void) {
    u8 i;

    D_800E1550 = 0;
    for (i = 0; i < 6; i++) {
        D_80090D50[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        D_80090D64[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        D_800E25F8[i] = 0xFF;
    }
    for (i = 0; i < 0x18; i++) {
        D_800E25E0[i] = -1;
    }
    SsInit();
    SsSetTableSize(&D_800E1560, 3, 8);
    SsSetTickMode(1);
    SsUtSetReverbType(0);
}

#include "common.h"

#include "psyq/libsnd.h"
#include "mmx6/globals.h"
void func_80058574(void);
void func_8005BA04(void);

void func_80016A4C(void) {
    s8 i;

    for (i = 0; i < 6; i++) {
        if (D_80090D50[i] != -1) {
            SsVabClose(D_80090D50[i]);
            D_80090D50[i] = -1;
        }
    }
    for (i = 0; i < 6; i++) {
        if (D_80090D64[i] != -1) {
            SsSepClose(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    func_8005BA04();
    SsUtSetReverbType(0);
    SsUtSetReverbDepth(0, 0);
    SsEnd();
    func_80058574();
}

#include "common.h"

#include "psyq/libsnd.h"
#include "mmx6/globals.h"

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
            SsSepClose(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    for (i = 0; (t = i, u = t < 6, u); i++) {
        if (D_80090D50[i] != -1) {
            SsVabClose(D_80090D50[i]);
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
