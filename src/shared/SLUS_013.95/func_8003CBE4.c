#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern void (*D_80073CF4[])(u8*);

void func_8003CBE4(u8* arg0) {
    s32 idx;

    if (D_800CCED0.unk1E != 0) {
        arg0[3] = 1;
        D_800CCED0.unk1F = 1;
        idx = 0;
        if (D_800CCED0.stage == 0xC) {
            if (D_800CCED0.substage == 0) {
                s32 t = (u8)D_800CCED0.checkpoint - 2;
                idx = (u32)t < 0x10U;
            }
        }
        arg0[4]++;
        D_80073CF4[idx](arg0);
    }
}
