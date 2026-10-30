#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern void (*D_80073CF4[])(u8*);

void func_8003CBE4(u8* arg0) {
    s32 idx;

    if (g_playthrough_state.unk1E != 0) {
        arg0[3] = 1;
        g_playthrough_state.unk1F = 1;
        idx = 0;
        if (g_playthrough_state.stage == 0xC) {
            if (g_playthrough_state.substage == 0) {
                s32 t = (u8)g_playthrough_state.checkpoint - 2;
                idx = (u32)t < 0x10U;
            }
        }
        arg0[4]++;
        D_80073CF4[idx](arg0);
    }
}
