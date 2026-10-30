#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_800ED3DC(u8* arg0) {
    if (g_playthrough_state.character_state.bytes[6] == 1) {
        s32 v = arg0[3];
        g_playthrough_state.character_state.bytes[6] = 2;
        g_playthrough_state.character_state.bytes[5] = v;
        arg0[2]++;
    }
}
