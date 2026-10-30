#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800709F4[];
M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);

#define F17F6C_ENG_SB(off) (*((s8*)&g_playthrough_state + (off)))
#define F17F6C_ENG_B(off) (*((u8*)&g_playthrough_state + (off)))

void func_80017F6C(void) {
    u8 v;

    if (g_playthrough_state.stage == 0xC &&
        (v = 0x1B, g_playthrough_state.substage != 0)) {
        if (F17F6C_ENG_SB(0x31) == 1) {
            v = 0x14;
        }
    } else if (g_playthrough_state.stage == 0) {
        v = 0x15;
        if (F17F6C_ENG_SB(0x26) != 0) {
            v = 0x17;
        }
    } else if (g_playthrough_state.stage >= 0x13) {
        v = 0x18;
        if (F17F6C_ENG_B(0x43B) == 0) {
            v = 0x19;
        } else if (F17F6C_ENG_B(0x43B) == 1) {
            v = 0x17;
        }
    } else {
        v = D_800709F4[g_playthrough_state.stage * 2];
    }
    play_bgm_xa_track(v, D_800709F4[g_playthrough_state.stage * 2 + 1]);
}

#undef F17F6C_ENG_SB
#undef F17F6C_ENG_B
