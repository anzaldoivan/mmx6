#include "common.h"

void SsSepClose(s8);
void SsEnd(void);
void func_80058574(void);
void SsUtSetReverbDepth(s32, s32);
void SsUtSetReverbType(s32);
void func_8005BA04(void);
void SsVabClose(s32);
extern s8 D_80090D50[6];
extern s8 D_80090D64[];

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
