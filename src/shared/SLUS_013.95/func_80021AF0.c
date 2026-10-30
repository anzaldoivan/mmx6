#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern s8* D_80071CB8[][2];

#define ENG_B(off) (*((u8*)&g_playthrough_state + (off)))
#define ENG_SB(off) (*((s8*)&g_playthrough_state + (off)))

s32 func_80021AF0(s32 arg0) {
    s8 v;

    if (arg0 == 2 && g_playthrough_state.stage >= 0x13) {
        v = 0x16;
        if (ENG_B(0x43B) != 0) {
            v = 0x15;
            if (ENG_B(0x43B) == 1) {
                v = 8;
            }
        }
        return v & 0xFF;
    }
    v = D_80071CB8[g_playthrough_state.stage][g_playthrough_state.substage]
                  [arg0];
    if (v == -1) {
        if (ENG_SB(0x38) == 0) {
            if (ENG_B(0x5E) == 0) {
                v = 0;
            } else if (ENG_B(0x5E) == 4) {
                v = 2;
            } else if (ENG_B(0x5E) == 1) {
                v = 3;
            } else if (ENG_B(0x5E) == 2) {
                v = 4;
            } else {
                v = 5;
            }
        } else {
            v = 1;
            if (ENG_B(0x5F) & 0x20) {
                v = 6;
            }
        }
    }
    return v & 0xFF;
}
