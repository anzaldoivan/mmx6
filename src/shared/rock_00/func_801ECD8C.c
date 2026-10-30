#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_801ECD8C(void* arg0) {
    s32 v;

    v = *(u8*)((u8*)arg0 + 0xE1) + 1;
    *(u8*)((u8*)arg0 + 0xE1) = v;
    if ((u32)(v & 0xFF) >= 0x3C) {
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk19 = 0;
        g_playthrough_state.unk18 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.gameplay_locked = 0;
        *(u8*)((u8*)arg0 + 6) = *(u8*)((u8*)arg0 + 6) + 1;
    }
}
