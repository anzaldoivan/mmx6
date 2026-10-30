#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D330();
extern struct X4_EngineObj g_playthrough_state;

void func_80051C08(s8* arg0) {
    if (arg0[0x45] != 0) {
        func_8003D330();
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk17 = 0;
        arg0[5]++;
    }
}
