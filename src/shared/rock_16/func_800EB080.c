#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F1CB0[];
extern u8 D_800F1CEB;

#define EB080_SEL (g_playthrough_state.character_state.bytes[10])
#define EB080_DIR (g_playthrough_state.character_state.bytes[11])
#define EB080_DONE (g_playthrough_state.character_state.bytes[12])
#define EB080_F(o, t) (*(t*)((u8*)arg0 + (o)))

void func_800EB080(void* arg0) {
    s32 old;

    old = EB080_SEL;
    if (g_pad1_buttons[2] & 0x8000) {
        EB080_DIR = 1;
        EB080_SEL--;
        if (EB080_SEL < 0) {
            EB080_SEL = D_800F1CEB - 1;
        }
    } else if (g_pad1_buttons[2] & 0x2000) {
        EB080_DIR = 2;
        EB080_SEL++;
        if (EB080_SEL >= D_800F1CEB) {
            EB080_SEL = 0;
        }
    }
    if (old != EB080_SEL) {
        play_sound(5, 0, 0);
        EB080_F(0x8, s16) = 0;
        EB080_F(0x2, u8) += 1;
        return;
    }
    if (g_pad1_buttons[2] & 0x840) {
        u8 v = D_800F1CB0[old];
        EB080_F(0x5E, u8) = v;
        if (v == 5) {
            EB080_F(0x38, u8) = 1;
        } else {
            EB080_F(0x38, u8) = 0;
        }
        play_sound(5, 1, 0);
        EB080_DIR = 3;
        EB080_F(0x8, s16) = 0;
        EB080_F(0x2, u8) += 2;
        return;
    }
    if (g_pad1_buttons[2] & 0x10) {
        EB080_F(0x2, u8) = 9;
        EB080_DONE = 1;
        EB080_F(0x8, s16) = 0;
    }
}
