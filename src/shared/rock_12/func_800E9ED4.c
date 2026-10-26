#include "common.h"
#include "psyq/libspu.h"

void SsSepClose(s8);
s32 SsSepOpen(void*, s8, s32);
void SsSepSetVol(s8, u32, s32, s32);
void SsUtSetReverbDepth(s32, s32);
void SsUtSetReverbType(s32);
void func_8005BA24(void);
extern s8 D_80090D55;
extern s8 D_80090D64[];
extern s32 D_800E0D38;

void func_800E9ED4(void) {
    s32 t;

    if (D_80090D64[5] != -1) {
        SsSepClose(D_80090D64[5]);
    }
    t = SsSepOpen((void*)D_800E0D38, D_80090D55, 1);
    D_80090D64[5] = t;
    SsSepSetVol(t, 0, 0x7F, 0x7F);
    SsUtSetReverbType(3);
    while (SpuClearReverbWorkArea(3) == -1) {
    }
    func_8005BA24();
    SsUtSetReverbDepth(0x40, 0x40);
}
