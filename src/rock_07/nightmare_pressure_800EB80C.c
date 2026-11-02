#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
extern s8 D_800970A5;
extern s8 D_80097298;
extern struct X4_EngineObj g_playthrough_state;

// 0x800EB80C init_nightmare_pressure: Nightmare Pressure sub-boss start.
// basis: community tweaks-index.tsv:182
// callers: none known
void init_nightmare_pressure(void* arg0) {
    if (D_800970A5 == 0x14) {
        D_80097298 = 1;
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = arg0;
        M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x30;
        set_boss_level(0);
        {
            // !FAKE: pin the increment temp to the register retail uses
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 0x6) + 1;
            M2C_FIELD(arg0, u8*, 0x6) = t;
        }
    }
}
