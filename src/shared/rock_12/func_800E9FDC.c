#include "common.h"

void SsSepClose(s8);
void SsUtSetReverbDepth(s32, s32);
void SsUtSetReverbType(s32);
void func_8005BA04(void);
extern s8 D_80090D64[];

void func_800E9FDC(void) {
    SsSepClose(D_80090D64[5]);
    D_80090D64[5] = -1;
    func_8005BA04();
    SsUtSetReverbType(0);
    SsUtSetReverbDepth(0, 0);
}
