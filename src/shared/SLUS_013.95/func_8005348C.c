#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_8008EAFC;
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
M2C_UNK func_8003D330();

void func_8005348C(struct X4_MainObj* arg0) {
    if (*(u16*)&arg0->bg_offset != 0) {
        g_Player.unk71 |= 8;
    }
    if (D_8008EAFC == 0) {
        if (arg0->unk2 & 0xF0) {
            g_playthrough_state.unk10 = 0;
        }
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk19 = 0;
        g_playthrough_state.unk18 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        func_8003D330();
        arg0->state++;
    }
}
