#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F1CB0[];

void func_800ECD80(u8* arg0) {
    if (++*(s16*)(arg0 + 8) >= 8) {
        *(s16*)(arg0 + 8) = 0;
        g_playthrough_state.character_state.bytes[11] = 0;
        g_playthrough_state.character_state.bytes[2] =
            D_800F1CB0[g_playthrough_state.character_state.bytes[10]];
        arg0[2]--;
    }
}
