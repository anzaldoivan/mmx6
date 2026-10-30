#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80013008(void);
void silence_sound(u8, u8);
void stop_cd_audio();
M2C_UNK func_80025FB0();

extern s32 D_8008EC0C;
extern s8 D_80097424;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCED1;
extern s8 D_800E3140;
extern u8 D_800E3141;

// 0x800346EC exit_stage_from_menu: scene triggers on exit stage.
// basis: community tweaks-index.tsv:310
// callers: none known
void exit_stage_from_menu(u8* self) {
    if (D_80097424 == 0) {
        if (*(s32*)(self + 0x38) == 0) {
            D_800CCED1 = 0;
            self[4] = 0;
            self[5] = 0;
        } else {
            s8* e = (s8*)&g_playthrough_state;
            D_800E3140 = 2;
            e[0x10] = 0;
            e[0x11] = 0;
            e[0x12] = 0;
            e[0x13] = 0;
            e[0x14] = 0;
            e[0x15] = 0;
            e[0x16] = 0;
            e[0x17] = 0;
            D_8008EC0C = 0;
            D_800E3141 = e[0xC];
            self[4] = 0;
            self[5] = 0;
            silence_sound(0xFF, 0);
            stop_cd_audio();
            func_80013008();
            D_8008EC0C = 0;
            g_playthrough_state.state = 0xB;
            e[1] = 0;
            e[2] = 0;
            if ((u8)e[0x66] < 3U) {
                s8* q = e + 0xD2;
                if (*(s16*)(q + e[0x38] * 2) >= 0xBB8) {
                    g_playthrough_state.state = 0x13;
                    e[0x1D] = 5;
                    e[1] = 0;
                    e[2] = 0;
                    e[3] = 0;
                }
            }
        }
    }
    if (*(s32*)(self + 0x38) == 0) {
        func_80025FB0();
    }
}
