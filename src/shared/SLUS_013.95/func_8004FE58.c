#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8004FE58(s32 arg0, s8 arg1) {
    u8 v = arg0;

    g_playthrough_state.unk10 = v;
    g_playthrough_state.unk11 = v;
    g_playthrough_state.unk12 = v;
    g_playthrough_state.unk13 = v;
    g_playthrough_state.unk14 = v;
    g_playthrough_state.unk15 = v;
    g_playthrough_state.unk16 = v;
    g_playthrough_state.unk17 = v;
    g_playthrough_state.unk19 = v;
}
