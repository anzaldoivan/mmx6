#include "common.h"
#include "mmx6/x4.h"

extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800CCF3A;
extern s8 D_800E3140;
extern u8 D_800E3141;

void func_8001F0C8(u8* self) {
    s8* g = (s8*)&D_80097420;

    if (g[4] == 0) {
        switch ((u8)g[7]) {
        case 0: {
            self[0x1E] = 0;
            if (D_800CCF3A & 0x8000) {
                self[0x39] = 4;
            } else {
                self[0x39] = 2;
            }
            self[0] = 9;
            self[1] = 0;
            self[2] = 0;
            self[3] = 0;
            return;
        }
        case 1: {
            s8* e = (s8*)&g_playthrough_state;
            D_800E3140 = g[7];
            D_800E3141 = e[0xC];
            self[0] = 0xB;
            self[1] = 0;
            self[2] = 0;
            self[3] = 0;
            if ((u8)e[0x66] < 3U) {
                s8* q = e + 0xD2;
                if (*(s16*)(q + e[0x38] * 2) >= 0xBB8) {
                    g_playthrough_state.state = 0x13;
                    e[0x1D] = 5;
                    e[1] = 0;
                    e[2] = 0;
                    e[3] = 0;
                    return;
                }
            }
            break;
        }
        case 2:
        default:
            self[1] = 5;
            break;
        }
    }
}
