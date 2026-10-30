#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_8003D9F8(void* arg0);

void func_8003D954(u8* arg0) {
    if (--((s8*)arg0)[0xD7] == 0) {
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk18 = 0;
        g_playthrough_state.unk19 = 0;
        g_playthrough_state.unk1A = 0;
        arg0[3] = 0;
        play_sound(3, 0x10, arg0);
        play_sound(3, 0xE, arg0);
        arg0[0xD7] = 0;
        arg0[0xD6] = 0;
        arg0[5]++;
        func_8003D9F8(arg0);
    }
}
